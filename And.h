#include "Base.h"
#ifndef AND_H
#define AND_H

class And: public Base{         // declaring the And class inherits from the base
    Base* Left;                 // variables inside
    Base* Right;
    
    public:
    And(){}; 
    ~And();
    And(Base*, Base*);          // constructor  with two base classes
    virtual bool execute(int, int);     // virtual function that we execute the two commands inside
};
#endif