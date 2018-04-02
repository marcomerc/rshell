#include "Base.h"
#include "rightD.h"

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
#include <iostream>
using namespace std;
bool rightD::execute(int inp, int outp){  
    
    
    pid_t pid;
    string file = Right->Get_FileName();
    
  
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int fd = open(file.c_str(), O_WRONLY | O_CREAT | O_TRUNC, mode);
    int in = dup(0);
    int out = dup(1);
   
    // got to make a case if there is a file going to another file
    pid = fork();
    int status; //use for foking and checking certain condition
    if(pid == -1)
    {
        perror("failed at forking");
    }
    else if(pid == 0)
    {
        //cout << "execute: \n";
        if( dup2(fd,1) == -1) {
            perror("dup");
            return false;
        }
         Left->execute(0,fd);
       
    }
    else if (pid > 0)
    {
    //cout << "eeew: \n";
        wait(&status);
        wait(0);
        
        Left->execute(0,fd);
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
        //  Left->execute(0,fd);
         //cout << "eeew: \n";
    dup2(in,0);
    dup2(out,1);
    return true;
}