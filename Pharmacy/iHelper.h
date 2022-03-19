#pragma once

#include <iostream>
#include <windows.h>
#include <ctime>

namespace iHelper
{
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

    inline void SizeConsole( int width , int height )
    {
        HWND hWindowConsole = GetConsoleWindow();
        HMENU hm = GetSystemMenu( hWindowConsole , FALSE );
        RECT r;
        GetWindowRect( hWindowConsole , &r ); //stores the console's current dimensions
        MoveWindow( hWindowConsole , r.left , r.top , width , height , TRUE );
        RemoveMenu( hm , SC_SIZE , MF_BYCOMMAND | MF_REMOVE );
        RemoveMenu( hm , SC_MAXIMIZE , MF_BYCOMMAND | MF_REMOVE );
        DrawMenuBar( hWindowConsole );
    }

    inline void deleteRR()
    {
        HWND consoleWnd = GetConsoleWindow();
        DWORD consoleStyle = GetWindowLong( consoleWnd , GWL_STYLE );
        consoleStyle &= ~( WS_MAXIMIZEBOX );
        SetWindowLong( consoleWnd , GWL_STYLE , consoleStyle );
    }
}