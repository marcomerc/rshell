#include "And.h"
#include <unistd.h> //library for Fork, execvp, watpid
#include <stdio.h>  //for perror
#include <stdlib.h> // for malloc
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/types.h> 

using namespace std;

And::And(Base* l, Base* r){      // initializer the constructor for vase 
    Left = l;                    // we use composite pattern 
    Right = r;                    // set it to the variables inside the And;
}

And::~And()
{

}
bool And::execute(int inp, int  outp){    // fucntion of And that excutes the two commands
   
   
            int in = dup(0);
            int out = dup(1);
    if(Left->execute(inp,  outp ) == true ){   // if the left command executes excute the right
            // dup2(in,0);
            // dup2(out,1);
            
        bool well=  Right->execute(inp, outp);           // fucntion of And that excutes the two command
            
            return well;
    }
    else{
            dup2(in,0);
            dup2(out,1);
        return false;               // else you don't execute the right and return false
    }
}
