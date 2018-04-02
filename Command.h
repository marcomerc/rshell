#include <string>
#include <vector>
#include "Base.h"
#ifndef COMMAND_H
#define COMMAND_H 

using namespace std;

class Command: public Base{
    vector<string> c;       // stores the command follow by the flags in the vector 
    
    public:
    Command(){};                    // constructor 
  
    Command(vector<string> c){      // passed in a vector
        this->c = c;
    };

    // so that it opens it fork with the command. and return if it excuted or not. look at the assignment for more instructions
    virtual bool execute(int,int);
};
#endif