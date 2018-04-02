#include "Or.h"
#include "Base.h"
#include <iostream>
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



bool Or::execute(int inp, int outp){                     // calls the executed function 
 
    int in = dup(0);
    int out = dup(1);
 
    if(Left->execute(inp,outp) ==  false){          /// if the left executes then right executes
         dup2(in,0);
        dup2(out,1);
        bool temp = Right->execute(inp,outp);   
        dup2(in,0);
        dup2(out,1);
        if(temp == false){              // depending on the reuslt of right we return true or false
            return false;
        }
        else{
            return true;
        }
    }
    else{
        dup2(in,0);
        dup2(out,1);
        return true;
    }
    
}