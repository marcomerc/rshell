#include "Base.h"
#ifndef CONP_H
#define CONP_h

class ConP: public Base{
    Base* Left;
    Base* Right;
    
    public:
    Or(){};
    // set the left to the left  and right to the right.
    
    Or(Base* l, Base* r){
        Left = l;
        Right = r;
    } 

    // implement so that it calls the left excutes first then the right depends on the left's execution look at
    // at the manual for the assighment.
    virtual bool execute(){
        Left->execute();
    }
};
#endif