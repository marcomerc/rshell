#include "Semi.h"
#include <stdio.h>  //for perror and exit
#include <stdlib.h> // for malloc
#include <unistd.h> //library for Fork, execvp, watpid
#include <iostream>
#include <string>
#include <string.h>
#include <sys/wait.h>
#include <features.h> // for stats macro
#include <sstream>

#include <sstream>      // std::stringstream
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <features.h> // for stats macro

#include <stdlib.h>


#include <errno.h>


using namespace std;



Semi::Semi(vector<string> p)
{
    c = p;
}
Semi::~Semi(){
                
        c.erase( c.begin(),c.end() ); // this should work. the function .end() goes all the way to the last thing in the vector.

    
}

bool Semi::execute(int inp, int outp){
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
            if(f == ""){
                f = "-e";
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
            char t[1000];
            // strcpy(tab2, tmp.c_str());
            strcpy(t , line.c_str());
            
        
        
            FILE *in;
            
            char out[512]; //contains the output of the bash script
            if(!(in = popen(t, "r"))){ // t is the argument being pass into the bash script
              
            }
            else{
                
            }
            //this overwrites out to either (True) or (False)
            while(fgets(out, sizeof(out), in)!=NULL){
                cout << out;
            
            }
            //closes the bash script
            pclose(in);
            
            //check if the bash retunr true or false for the test command
            if(out[1] == 'T'){
              return true;
            }
            else{
                return false;
            }
            
        }else{
            
            
            //using the stat function to check for absolute path
            struct stat info;
            //check is a string that keeps track of the flag used for using the test command
            string check = f;
            //pathname is the name of the path we are going to check if there is a directory of file
            char pathname[1000];
            // strcpy(tab2, tmp.c_str());
            strcpy(pathname, path.c_str());

            //this function allows us to get information of the pathname and store it into "info"
            stat(pathname, &info);
            
        if(check == "-d")
        {
           
            if( stat( pathname, &info ) != 0 ) //checks if the path exits
            {
                cout << "(False)\n";
                return false;
            }
            else if( S_ISDIR(info.st_mode) )  //checks if the path leads to a directory and if so return true
            {
                cout << "(True)" << endl;
                return true;
            }
            else
            {
                cout << "(False)" << endl;   //return false if the path does not lead to a directory
                return false;
            }
        }
    
        else if(check == "-f")  
        {
             if( stat( pathname, &info ) != 0 ) // checks if the path exists
            {
                cout << "(False)" << endl;
                return false;
            }
            else if( S_ISREG(info.st_mode) )  //checks if the path leads to a regular file and if so return true
            {
                cout << "(True)" << endl;
                return true;
            }
            else
            {
                cout << "(False)" << endl;  //return false if the path does not lead to a regular file
                return false;
            }
        }
    
        else if(check == "-e")
        {
            if( stat( pathname, &info ) != 0 ) //checks if the path exists
            {
                cout << "(False)" << endl;
                return false;
            }
            else if(S_ISDIR(info.st_mode) || S_ISREG(info.st_mode))  //checks if the path leads to a direcotry or regular file and if so return true
            {
                cout << "(True)" << endl;
            return true;
            }
            else
            {
                cout << "(False)" << endl;        //return false if the path does not lead to a directory or regular file
                return false;
            }
        }
            

        }
        return false;
           
    }else{
    
    
    
    char **argc =  ( char**)malloc(sizeof(char**)*(c.size()+ 1));           // allocates memory for char**
    vector<char*> v;                                                        // vector use to in the transfer of files 
    for(unsigned int i = 0; i < c.size(); i++){                              // converts all the strings of the vector into the char*
    string commandss = c.at(i);                                             // copy of the string
    char*array = (char*)malloc(c.at(i).size());                             // allocate memory for the v.
    strcpy(array, commandss.c_str());                                       // copy string into char*
    array = strtok(array,"&|");                                             // break it down into word by word in char*
    v.push_back(array);                                                     // push word char* in the vector 

    }
    for(unsigned int i= 0; i < v.size();i++){                               // copys the vector conten into the argc
        argc[i] = v.at(i);
    }        
    argc[c.size()] = NULL;                                                  // buts a null at the end
    pid_t pid = fork();                                                      // initiate fork
    if (pid == 0){                                                          // child running 
        
        if( execvp(argc[0], argc)  == -1){ // probably needs to be <0;      // probably needs to be <0;  
        perror(argc[0]);
        return false;
        }
        else{
        //delete[] argv;
        return true;
        }
              
    } /// parent running                                                     /// parent running
    else if (pid > 0){
        wait(0);
        return true;
    }
    else
    {
        // fork failed
        cout << "Fork fails \n";
        exit(-1);
    }
        
    return true;
    }
    //return true;
}