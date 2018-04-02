#include "Base.h"
#include "rightDD.h"
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
#include <fcntl.h>
#include <iostream>
using namespace std;
bool rightDD::execute(int inp, int outp){  
    
  
    string file  = Right->Get_FileName();

   
    int outPut = open(file.c_str(), O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    int in = dup(0);
    int out= dup(1);
    
    
    pid_t pid = fork(); // forking begins 
    int status; //status for fork, using in wait
    
    if(pid == -1)
    {
        perror("fork");

    }else if(pid == 0)  //child process
    {
        dup2(outPut,1);
        Left->execute(1,0);
     
    }
    
    else if (pid > 0)   // parent process
    {
        wait(&status);
        wait(0);
        if(WIFEXITED(status)){
        if(WEXITSTATUS(status)){                        // outputs true or false dending on what happens in the child terminate with exit(2);
                return false;
            }
            return true;
        }
                
        if(WIFEXITED(status)){
            return false;
        }
        else {
            return true;
        }
    }
    dup2(in,0);
    dup2(out,1);
    
    return true;

}