#include <string>
#include <vector>
#include <fcntl.h>    /* For O_RDWR */
#include <unistd.h>   /* For open(), creat() */
#include "Base.h"
#ifndef COMMANDFILE_H
#define COMMANDFILE_H 

using namespace std;

class CommandFile: public Base{
    vector<string> c;       // stores the command follow by the flags in the vector 
    
    public:
    CommandFile(){};                    // constructor 
  
    CommandFile(vector<string> c){      // passed in a vector
        this->c = c;
    };

    // so that it opens it fork with the command. and return if it excuted or not. look at the assignment for more instructions
    virtual bool execute(int inp,int outp){
        string file = c.at(0);
        int  outPut = open(file.c_str(),O_RDONLY); // new file director
        id_t pid = fork(); // forking begins 
    int status;
    
    if(pid == 0)            //child process
    {
        dup2(inp,0);        //inp becomes the standard input
        dup2(outPut,1);       // outp becomes the standard output
        // close(inp);
        // close(outp);
       
    }
    
    else if(pid > 0)    //parent process
    {   
        cout << "file wait\n";
        // close(inp);
        wait(0);
        wait(&status);
            //wait(0);
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
            } //waits for the child process to finish before moving on ahead
        cout << "the end\n";
    }
        
        return true;
    }
    // return the first element of the vector
     string Get_FileName(){
         
         
         
        return c.at(0);
    }

};
#endif