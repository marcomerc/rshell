#include "Base.h"
#ifndef PIPE_H
#define PIPE_H
#include <string>
#include "Base.h"
#include "leftD.h"
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
#include "CommandP.h"

#include <stdlib.h>
#include <sstream>      // std::stringstream
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
// #include <features.h> // for stats macro
#include <sys/stat.h> 
#include <fcntl.h>
#include <iostream>
#include <vector>
using namespace std;

class Pipe: public Base{
    Base* Left;
    Base* Right;
    
    public:
    Pipe(Base* left, Base* right) {
        Right = right;
        Left =left;
    };
    // set the left to the left  and right to the right.
    
    Pipe(){
    };

    // implement so that it calls the left excutes first then the right depends on the left's execution look at
    // at the manual for the assighment.
    virtual bool execute(int inp, int outp);

};
#endif