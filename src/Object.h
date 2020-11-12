#include <stdio.h>

class Object
{
    public:
        virtual void calculate() 
        {
            printf("Object is not defined.");
        }
        virtual void draw()
        {
            printf("Draw is not defined.");
        }        
};