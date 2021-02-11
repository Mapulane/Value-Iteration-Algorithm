#ifndef _VIteration_H
#define _VIteration_H

#include  <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <fstream>
#include <string>
#include <cmath>


using namespace std;

namespace MKHMAP005{

class VIteration{
  public:
    int numStates;
    int numConvergence;
    float discountFactor;

    vector<int> terminalStates;
    vector<float> V;
    vector<float> Vp;
    vector<int> optPolicy;


// Functions to perform the value iteration
    VIteration(int nS, float dF);
    void createState(string filename);  // createStates
    bool terminalS(int state); //determine if state is terminal state
    int optimalPolicy(int state);
    void wirteOutput( string filename, int count);
    float BMcalculator(int state);

    struct transition{
      int state;
      float reward;

      transition(int st, float rew);
      bool operator<(transition rhs);

    };

    typedef std::vector<transition> transVector;
    vector<transVector> trans;

};

}
#endif
