#include <stdio.h>
#include "wVector2D.h"

namespace Puffer {
    class Object {
        public:
            virtual void Calculate(double delta)  {
                printf("Object is not defined.");
            }
            virtual void Draw() {
                printf("Draw is not defined.");
            }
            virtual v2d* GetPosition() {
                return new v2d();
            }
            virtual v2d* GetSize() {
                return new v2d();
            }
    };
}
