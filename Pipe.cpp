#include "Base.h"
#include "Pipe.h"

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
#include "CommandP.h"

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
#include <iostream>
using namespace std;
bool Pipe::execute( int inp, int outp){  
    
    // for pipe function 
    int fds[2];
   
     //pid_t pid;    
    int pcheck;
    pcheck = pipe(fds);
    if(inp == 1 && outp == 0){
        inp = fds[0];
        outp = fds[1];
    }
      
  
    
    if(pcheck <= -1)
    {
        cout << "error in piping" << endl;
    }
    // pid = fork();   //forking begins 
    
    // if(pid <0)
    // {
    //     cout << "failed" << endl;
    //     exit(0);
    // }
    // if(pid == 0 )
    // {

        // dup2(inp, 0); /// --- NS
        // dup2(outp, 1);
        // Left->execute(inp, fds[1]);
        //Left->execute(outp, 1);
        Left->execute(inp, fds[1]);
        close(fds[1]); // not having this causes infinte for loop
        Right->execute(fds[0], outp);
        close(fds[0]); // not having this cuases infintte for loop

    // }
    // else if(pid > 0){
        //wait(0);
        
    // }
        // dup2(fds[0], 0);
        //close(fds[0]);
        
        //Right->execute(outp,0);
    // }
    //cout << "end";
    return true;
}

// #include "Base.h"
// #include "Pipe.h"

// #include <sstream>      // std::stringstream
// #include <string.h>
// #include <stdlib.h>
// #include <vector>
// #include <stdio.h>
// #include <unistd.h>
// #include <sys/wait.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <features.h> // for stats macro
// #include <fstream> 
// #include "CommandP.h"

// #include <stdlib.h>
// #include <sstream>      // std::stringstream
// #include <vector>
// #include <sys/types.h>
// #include <sys/stat.h>
// // #include <features.h> // for stats macro
// #include <sys/stat.h> 
// #include <fcntl.h>

// #include <iostream>
// #include <iostream>
// #include <iostream>
// using namespace std;
// bool Pipe::execute( int inp, int outp){  
    
//     // for pipe function 
//     int fds[2];
   
//      //pid_t pid;    
//     int pcheck;
//     pcheck = pipe(fds);
//     if(inp == 1 && outp == 0){
//         inp = fds[0];
//         outp = fds[1];
//     }
      
  
    
//     if(pcheck <= -1)
//     {
//         cout << "error in piping" << endl;
//     }
//     // pid = fork();   //forking begins 
    
//     // if(pid <0)
//     // {
//     //     cout << "failed" << endl;
//     //     exit(0);
//     // }
//     // if(pid == 0 )
//     // {

//         // dup2(inp, 0); /// --- NS
//         // dup2(outp, 1);
//         // Left->execute(inp, fds[1]);
//         //Left->execute(outp, 1);
//         Left->execute(inp, fds[1]);
//         close(fds[1]); // not having this causes infinte for loop
//         Right->execute(fds[0], outp);
//         close(fds[0]); // not having this cuases infintte for loop

//     // }
//     // else if(pid > 0){
//     //     wait(0);
        
//     // }
//         // dup2(fds[0], 0);
//         //close(fds[0]);
        
//         //Right->execute(outp,0);
//     // }
//     //cout << "end";
//     return false;
// }

