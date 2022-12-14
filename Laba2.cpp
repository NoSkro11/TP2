#include <iostream>
#include "Menues.h"
int main()
{
    setlocale(0, "");
    
    int n = 0;
    bool flag = true;
    try {


        while (flag)
        {
            std::cout << "\n----------------MAIN MENU-----------------\n";
            std::cout << "1-st programm\n2-nd programm\n";
            std::cin >> n;
            switch (n)
            {
            case 1:
                menuFirst();
                break;
            case 2:
                menuSecond();
                break;
            default:
                flag = false;
                break;
            }


        }


    }
    catch (const char* exception) {
        std::cout << exception;

    }



    return 0;
}