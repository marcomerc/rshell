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
// #include <fcntl.hs.h> // for stats macro

#ifndef LEFTD_H
#define LEFTD_H
#include <string>
using namespace std;

class leftD: public Base{
    Base* Left;
    CommandFile* Right;
    
    public:
    leftD(Base* left,CommandFile* right) {
        Left = left;
        Right = right;
    };
    // set the left to the left  and right to the right.
    
    leftD(){
        //cout << "default constructor" << endl;
        // Right;
        // Left;
    };

    // implement so that it calls the left excutes first then the right depends on the left's execution look at
    // at the manual for the assighment.
    virtual bool execute(int,int);
};
#endif