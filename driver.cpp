#include <iostream>
#include <sstream>
#include <string>
#include "VIteration.h"

using namespace std;
using namespace MKHMAP005;

int main(int argc, char* argv[]){

  int ns = 6;
  float df = 0.8;

  cout<< "*******************************************************"<<endl;
  cout<< "#                                                     #"<<endl;
  cout<< "#         WELCOME TO The VALUE ITERATION ALGORITHM    #"<<endl;
  cout<< "#                                                     #"<<endl;
  cout<< "*******************************************************"<<endl;

  if(argc == 5){
    string inputFile = argv[1];
    string outputFile = argv[2];
    ns = atoi(argv[3]);
    df = atof(argv[4]);

    //create value iteration object
    VIteration  vi(ns,df);
    vi.createState(inputFile);

    //initialise numStates
    vi.V.resize(vi.numStates,0);
    vi.Vp.resize(vi.numStates,0);

    //perform the bellman calulation until convegence is reached
    int count=0;
    while(vi.numConvergence < vi.numStates){
      count++;
      vi.numConvergence =0;

      for(int i=0; i<vi.numStates; i++){
        vi.Vp[i] = vi.BMcalculator(i);
      }
      vi.V=vi.Vp;

    }

    //calculate the optimal policy for each state
    for(int i=0; i<vi.numStates; i++){
      vi.optPolicy.push_back(vi.optimalPolicy(i));
    }

    //write to output1
    cout<< "Computing the Optimal policy using the Bellman Equation......."<<endl;
    vi.wirteOutput(outputFile, count);


  }
  else{cout<< "Use correct number of parameters"<<endl;}


}
