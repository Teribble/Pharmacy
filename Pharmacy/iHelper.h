#pragma once

#include <iostream>
#include <windows.h>
#include <ctime>
#include "Console.h"
#include "StaticTable.h"
#include <string>
#include<iterator>
#include<algorithm>

#pragma warning(disable : 4838)

#define NULL 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FORE 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define ESCAPE 27

#define VK_NULL 0x30
#define VK_ONE 0x31
#define VK_TWO 0x32
#define VK_THREE 0x33
#define VK_FORE 0x34
#define VK_FIVE 0x35
#define VK_SIX 0x36
#define VK_SEVEN 0x37
#define VK_EIGHT 0x38
#define VK_NINE 0x39
#define VK_ENTER 13

#define VK_ARROW_UP 72
#define VK_ARROW_DOWN 80
#define VK_ARROW_LEFT 75
#define VK_ARROW_RIGHT 77

#define coordError 60, 9

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

    inline void deleteCursor()
    {
        HWND consoleWnd = GetConsoleWindow();
        DWORD consoleStyle = GetWindowLong( consoleWnd , GWL_STYLE );
        consoleStyle &= ~( WS_MAXIMIZEBOX );
        SetWindowLong( consoleWnd , GWL_STYLE , consoleStyle );
    }

    inline void setCursor( int x , int y )
    {
        HANDLE console = GetStdHandle( STD_OUTPUT_HANDLE );
        COORD cursorPosition{ x,y };
        SetConsoleCursorPosition( console , cursorPosition );
    }

    inline std::string enterString()
    {
        std::string buffer;
        getline( std::cin , buffer );
        return buffer;
    }

    inline void clearScreen()
    {
        for(size_t i = 0; i < 20; i++)
        {
            for(size_t i = 0; i < 200; i++)
            {
                std::cout <<Terrible::bg_black<< " ";
            }
            std::cout << std::endl;
        }
    }

    inline int getIntDisappearingInscription( std::string str , int x , int y )
    {
        int num;
        iHelper::setCursor( x , y );
        std::cout << str;
        while(!( std::cin >> num ))
        {
            iHelper::setCursor( coordError );
            std::cout << Terrible::fg_red << "ERROR" << RESET;
            Sleep( 500 );
            iHelper::setCursor( x , y );
            for(int i = 0; i < NINE * NINE + NINE; i++)
            {
                
                std::cout << " ";
            }
            iHelper::setCursor( x,y );
            std::cout << str;
            std::cin.clear(); /*—брасываем ошибку*/
            while(std::cin.get() != '\n') continue;
        }
        iHelper::setCursor( x , y );
        for(int i = 0; i < str.size() + NINE; i++)
        {
            std::cout << " ";
        }
        return num;
    }

    inline std::string getStrDisappearingInscription( std::string str , int x , int y )
    {
        std::string buffer;
        iHelper::setCursor( x , y );
        std::cout << str;
        std::cin >> buffer;
        //getline( std::cin , buffer );
        iHelper::setCursor( x , y );
        for(int i = 0; i < str.size() + buffer.size(); i++)
        {
            std::cout << " ";
        }
        return buffer;
    }

    inline float getFloatDisappearingInscription( std::string str , int x , int y )
    {
        float num;
        iHelper::setCursor( x , y );
        std::cout << str;
        while(!( std::cin >> num ))
        {
            iHelper::setCursor( coordError );
            std::cout << Terrible::fg_red << "ERROR" << RESET;
            Sleep( 500 );
            iHelper::setCursor( x , y );
            for(int i = 0; i < NINE * NINE + NINE; i++)
            {

                std::cout << " ";
            }
            iHelper::setCursor( x , y );
            std::cout << str;
            std::cin.clear();
            while(std::cin.get() != '\n') continue;
        }
        iHelper::setCursor( x , y );
        for(int i = 0; i < str.size() + NINE; i++)
        {
            std::cout << " ";
        }
        return num;
    }

    inline void errorMessage( std::string message, int x, int y )
    {
        iHelper::setCursor( x , y );
        std::cout << Terrible::fg_red << message << RESET;
        Sleep( 800 );
        iHelper::setCursor( x , y );
        for(int i = 0; i < message.size(); i++)
        {
            std::cout << " ";
        }
    }

}