#include <iostream>
#include <windows.h>

int main(){
    SetConsoleOutputCP(CP_UTF8);

    int prices[] = {0, 2, 4, 6, 8};

    std::cout << prices[0] << std::endl;
    std::cout << prices[3] << std::endl;

    prices[3] = 12;
    std::cout << prices[3] << std::endl;



    return 0;
}