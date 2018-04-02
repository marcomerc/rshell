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
bool leftD::execute(int inp, int endp){  
    
    
    

    // if(pcheck <= -1)
    // {
    //     cout << "error in piping" << endl;
    // }
    
    // cout << "left side\n";
    // // Left->execute(inp, fds[1]);
    // // close(fds[1]); // not having this causes infinte for loop
    //     cout << "right side\n";
    // string file = Right->Get_FileName();
    // int  outPut = open(file.c_str(),O_RDONLY); // new file director
    // dup2(outPut,0);
    // Right->execute(fds[0],endp );
    // close(fds[0]); // not having this cuases infintte for loop

    
    
    string file = Right->Get_FileName();
    
    int  outPut = open(file.c_str(),O_RDONLY); // new file director
    //int in = dup(0); // standard input
    //int out =  dup(1); // standard output
    
    dup2(inp,1);
    pid_t pid = fork();       //forking begins  
    int status;
    if(pid == -1) {                          
        perror("fork");                      
    }
    else if (pid == 0) {        //child process
     int in = dup(0); // standard input
    int out =  dup(1); // standard output
    
        if(dup2(outPut,inp) <= -1) {
            perror("dup");
            return false;
        }
         dup2(endp,1);
        Left->execute(outPut, 1);
        dup2(in,0);
        dup2(out,1); // to res
        _Exit(0);
    }
    else if(pid > 0) // parent process
    {         
        //cout <" parent \n";
        
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
        //  wait(0);   // waints for shiild process to finish
    // dup2(in,0);
    // dup2(out,1); // to restore standard output(terminal) porb goes in child process
    return true;
}
