#include "Base.h"
#ifndef RIGHTDD_H
#define RIGHTDD_H
#include <string>
#include "Base.h"
#include "Command.h"
#include <iostream>
#include <sstream>      // std::stringstream
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <features.h> // for stats macro
#include <fstream> 

#include <stdlib.h>
#include <sstream>      // std::stringstream
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
// #include <features.h> // for stats macro
#include <sys/stat.h> 
#include "CommandFile.h"
#include <vector>
using namespace std;

class rightDD: public Base{
    Base*   Left;
    CommandFile* Right;
    
    public:
    rightDD( Base* left, CommandFile *right) {
        Left =left;
        Right =right;
    };
    // set the left to the left  and right to the right.
    
    rightDD(){
    };

    // implement so that it calls the left excutes first then the right depends on the left's execution look at
    // at the manual for the assighment.
    virtual bool execute(int inp, int outp);
};
#endif