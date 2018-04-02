#include <string>
#include <vector>
#include "Base.h"
#ifndef COMMANDS_H
#define COMMANDS_H 
#include "Command.h"
#include <unistd.h> //library for Fork, execvp, watpid
#include <stdio.h>  //for perror
#include <stdlib.h> // for malloc
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/types.h> 
#include "rightDD.h"

#include <sstream>      // std::stringstream
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <features.h> // for stats macro









using namespace std;

class CommandS: public Base{
    vector<string> c;       // stores the command follow by the flags in the vector 
    
    public:
    CommandS(){};                    // constructor 
  
    CommandS(vector<string> c){      // passed in a vector
        this->c = c;
    };

    // so that it opens it fork with the command. and return if it excuted or not. look at the assignment for more instructions
    virtual bool execute(int inp,int outp){
    
          char **argc =  ( char**)malloc( sizeof( char** )*(1000 ) );   // allocates memory for char**
    vector<char*> v;                                            // vector use to in the transfer of files 
    for( unsigned int i = 0; i < c.size(); i++ ){                 // converts all the strings of the vector into the char*
        string commandss = c.at( i );                                 // copy of the string
        char*array = ( char* )malloc( c.at( i ).size() );                 // allocate memory for the v.
        strcpy( array, commandss.c_str() );                           // copy string into char*
        
        array = strtok( array,"&|" );                                 // break it down into word by word in char*
        v.push_back( array );                                         // push word char* in the vector 
        

    }
    for( unsigned int i= 0; i < v.size();i++ ){                   // copys the vector conten into the argc
        //cout << v.at(i) << " ";
        argc[i] = v.at(i);                          
    }
    // cout <" Command end\n";
    argc[c.size()] = NULL; 
        
        
        
     if( execvp(argc[0], argc)  == -1){   //executes the command                   // probably needs to be <0;  
                perror(argc[0]);
                exit(2);
        }
    }
    
    // dup2(inp,0);
    // dup2(outp,1);
};
#endif