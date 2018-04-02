#include <string>
#include <vector>
#include "Base.h"
#ifndef CONNECTOR_H
#define CONNECTOR_H 

using namespace std;

class Connector: public Base{
    Base* L;    //left side of connector
    Base* R;    //right side of connector
    public:
    Connector(){};                    // constructor 
  
    Connector(Base*l,Base*r){      // passed in a vector
        L = l;
        R = r;
    };

    // so that it opens it fork with the command. and return if it excuted or not. look at the assignment for more instructions
    virtual bool execute(int inp ,int outp){
            L->execute(inp, outp);
            return R->execute(inp, outp);
    }
};
#endif