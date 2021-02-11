#include  <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <fstream>
#include <string>
#include <cmath>

#include "VIteration.h"

using namespace MKHMAP005;
using namespace std;


//value iteration constructor
VIteration::VIteration(int nS, float dF): numStates(nS), discountFactor(dF){
    numConvergence = 0;
}

// create states
void VIteration::createState(string file){

  int state;
  float reward;
  string line;
  ifstream infile(file);

  if(infile.is_open()){

      //create numStates
      for(int i = 0; i<numStates; i++ ){
        transVector tv;
        bool terminate = false;
        getline(infile, line);
        istringstream st(line);

        while (!st.eof()){
          st >>state >> reward;

          //find the terminating states
          if(i==state-1){
            terminate=true;
          }

          //add the transtions into the vector
          tv.push_back(transition(state-1, reward));
        }

        trans.push_back(tv);

        // add the terminal state into a vector
        if(terminate && tv.size()==1){
          terminalStates.push_back(i);
        }
      }

      infile.close();
      cout<< "File opend successfully"<<endl;

    }
    else{
      cout<< "File could not be opened"<<endl;
    }

}

//check for terminal state
bool VIteration::terminalS(int state){
  return find(terminalStates.begin(),terminalStates.end(),state) != terminalStates.end();
}

//find the Optimal policy for a given state
int VIteration::optimalPolicy(int state){

  int maxState = -1;
  float value = -1;
  bool maxValue = false;
  bool stateT = false;

  transVector tv = trans[state];

//loop through all the transitions states
  for(int i=0; i<tv.size(); i++){
    int st = tv[i].state;

//find the terminal state
    if(terminalS(st)){
      if(!maxValue){
        stateT = true;
        maxState = st;
      }
    }

//calculation to take path with higher value
    if(Vp[st]> value){
      if(Vp[st] > Vp[state]){
        maxValue = true;
      }
      if(!stateT || maxValue){
        maxState =st;
        value = Vp[st];
      }
    }
  }
  return maxState;

}

// calculate the maximum or optimal value using Bellman equation
float VIteration::BMcalculator(int state){

    int maxValue = -1;
    float value =-1;
    transVector tv = trans[state];

    for(int i=0; i<tv.size();i++){
      transition action = tv[i];
      value= action.reward + ( discountFactor * V[action.state]);
      if(value > maxValue){
        maxValue = value;
      }

    }
    if(abs(V[state] - maxValue)< 0.0001) {
      numConvergence++;
    }
    return maxValue;

}



//transition constructor
VIteration::transition::transition(int st, float rew):state(st),reward(rew){}

//transtion operator function
bool VIteration::transition::operator<(transition rhs){
  return this->reward < rhs.reward;

}

void VIteration::wirteOutput( string outputFile, int count){
  int beginState =1, endState =3;

  //write to output file
  ofstream outfile(outputFile);
  if(outfile.is_open()){
    outfile <<" Number of Iteration for the algorithm to converge: "<<count<<endl;

  }

  outfile<< endl << " The Optimal values are:" << endl;
  for (int i = 0; i < numStates; i++) {
    outfile << "V*(" << i+1 << ")= " << Vp[i] << endl;
  }


  outfile<<endl<<endl << " The Optimal values are:" <<endl;
  for (int i = 0; i < numStates; i++) {
    outfile<< "pi*(" << i+1 << ") = " << optPolicy[i] +1 << endl;
  }



  outfile<< endl << "Optimal Policy from S("<<beginState<<") to S("<<endState<<") is: ";
  beginState = beginState -1;
  endState = endState -1;

  int optState = beginState;

  do{
    outfile<<optState+1 <<"--> ";
    optState = optPolicy[optState];
    }
    while(optState!=endState);
    outfile<<endState+1<<endl;

  outfile<<endl<<"Question 3:"<<endl;
  outfile<<"changing the reward function changes only the optimal values but the optimal policy remains the same."<<endl;
  outfile<<"it can be seen that changing reward function  from s2->s3 and S6->S3 linearly producesa slide different in the optimal values hence the policy remains the same."<<endl;

cout<< "Output file "<<outputFile<<" successfully written!!!!!"<<endl;
}
