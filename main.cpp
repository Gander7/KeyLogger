#include <iostream>
#include <windows.h>

using namespace std;

int main ()
{
    // Hack to hide Console Window
    MSG Msg;
    while(GetMessage (&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return 0;
}
