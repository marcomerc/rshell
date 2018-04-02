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
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <features.h> // for stats macro


using namespace std;




//use fork
bool Command::execute(int inp, int endp){
    
    
       if(c.size() == 1 && (c.at(0) == "test" || c.at(0) == "Test" ) ){
        return false;
    }

    if( ( (c.at(0) == "[" && c.at(c.size()-1) == "]") || c.at(0) == "test" ) && c.at(1) != "test" ){
        bool Absolute = false;
            string f = "";
            string path = "";
            for(unsigned int i = 0; i < c.size(); i++){
                if(c.at(i).size() > 1){  
                    if(c.at(i).at(0) == '/' ){
                        path = c.at(i);
                        Absolute = true;
                    }
                    if(c.at(i) == "-d" || c.at(i) == "-e" || c.at(i) == "-f"  ){
                        f = c.at(i);
                        
                    }
                }
            }
        if(Absolute == false){
            
            // string st = c.at(c.size());
            string line = "chmod 711 ex.sh; ./ex.sh";
            for(unsigned int i = 0; i < c.size(); i++){
                if(i == 0){
                    line =  line + " " + c.at(0);
                }else{
                    line = line + " " + c.at(i);
                }
            }
            
            //t stores the pathname to pass into the bash script
            char t[1000];
            
            strcpy(t , line.c_str());
            
        
        
            FILE *in;
            //out stores the output given by the bash script 
            char out[512]; 
            
            if(!(in = popen(t, "r"))){ // text is the argument
            
            }
            else{
                
            }
            while(fgets(out, sizeof(out), in)!=NULL){
                cout << out;
            
            }
            
            //closes the bash script 
            pclose(in);
            
            
            if(out[1] == 'T'){
              return true;
            }
            else{
                return false;
            }

        
            
            
            
            
            
        }else{
            
            //the stat function is used for absolute path
            struct stat info;
            //this a string that keeps track of the flag passed in the test command
            string check = f;
            // stores the path into the pathname
            char pathname[1000];
            
            //get the string of the path and put it into a char
            strcpy(pathname, path.c_str());

        //get information of the the path and store in the information into "info"
        stat(pathname, &info);
        if(check == "-d")
        {
            if( stat( pathname, &info ) != 0 ) //checks if the path is valid
            {
                cout << "(False)\n";
                return false;
            }
            else if( S_ISDIR(info.st_mode) )    // checks if the path leads to a directory if so return true
            {
                cout << "(True)" << endl;
                return true;
            }
            else
            {
                cout << "(False)" << endl;  // returns false if the path does not lead to a directory
                return false;
            }
        }
    
        else if(check == "-f")
        {
            if( stat( pathname, &info ) != 0 ) //checks if the path real/valid
            {
                cout << "(False)" << endl;
                return false;
            }
            else if( S_ISREG(info.st_mode) )  // checks if the path leads to a regular file if so return true
            {
                cout << "(True)" << endl;
                return true;
            }
            else
            {
                cout << "(False)" << endl; // return false if the path does not lead to a regular file
                return false;
            }
        }
    
    else if(check == "-e")
    {
        if( stat( pathname, &info ) != 0 )
        {
            cout << "(False)" << endl;
            return false;
        }
        else if(S_ISDIR(info.st_mode) || S_ISREG(info.st_mode))  // checks if the path leads to a directory or regular file if so return true
        {
            cout << "(True)" << endl;
            return true;
        }
        else
        {
            cout << "(False)" << endl; //return false if the path does not lead to a directory or regular file
            return false;
        }
    }
            

        }
        return false;
           
    }
    if(c.at(0) == "Test" || c.at(0) == "Test" ||
        c.at(0).at(0) == '[' || c.at(0).at(c.at(0).size()-1 ) == ']' ){
           
           cout << "test: command no found\n";
           return false;
      
    }else{

       
        int status;
        char **argc =  ( char**)malloc( sizeof( char** )*( c.size()+ 1 ) );   // allocates memory for char**
        vector<char*> v;                                            // vector use to in the transfer of files 
        for( unsigned int i = 0; i < c.size(); i++ ){                 // converts all the strings of the vector into the char*
            string commandss = c.at( i );                                 // copy of the string
            char*array = ( char* )malloc( 100);                 // allocate memory for the v.
            strcpy( array, commandss.c_str() );                           // copy string into char*
            array = strtok( array,"&|" );                                 // break it down into word by word in char*
            v.push_back( array );                                         // push word char* in the vector 
            
        }
        for( unsigned int i= 0; i < v.size();i++ ){                   // copys the vector conten into the argc
            argc[i] = v.at(i);                          
        }        
        argc[c.size()] = NULL;                                      // buts a null at the end
        pid_t pid = fork();                                          // initiate fork 
        
        if (pid == 0){                                              // child running 
            if( execvp(argc[0], argc)  == -1){                      // probably needs to be <0;  
                perror(argc[0]);
                exit(2);
            }
                    
                    
                  
        }                                                       /// parent running
        else if (pid > 0){
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
        else{
            // fork failed
            cout << "Fork fails \n";                        // outputs if fork fails
            exit(-1);
        }
        
           
            return true;
    }
}