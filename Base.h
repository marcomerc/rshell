#ifndef BASE_H
#define BASE_H

class Base {
    public:
        /* Constructors */
        Base() {};  
     
    
       
        /* Pure Virtual Functions */
        virtual bool execute(int inp, int endp ) = 0;
};

#endif