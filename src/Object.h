#include <stdio.h>

namespace Puffer {
    class Object {
        public:
            virtual void Calculate(double delta)  {
                printf("Object is not defined.");
            }
            virtual void Draw() {
                printf("Draw is not defined.");
            }        
    };
}
