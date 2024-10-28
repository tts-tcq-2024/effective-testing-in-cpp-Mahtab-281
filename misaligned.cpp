#include <iostream>
#include <assert.h>
#include <sstream>
#include <string>

void printOnConsole(std::string manualItem){
    std::cout << manualItem;
}

int printColorMap(void(*fp)(std::string)) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            fp(std::to_string(i * 5 + j ) + " | " + majorColor[i] + " | " + minorColor[i] + "\n");
        }
    }
    return i * j;
}
std::string actualManual;

// Test environment 
void mockPrintOnConsole(std::string manualItem)
{
    actualManual += manualItem;
}

int main() {
    int result = printColorMap(&mockPrintOnConsole);
    assert(result == 25);

    const std::string expectedConsoleBuffer =
        "0 | White | Blue\n"
        "1 | White | Orange\n"
        "2 | White | Green\n"
        "3 | White | Brown\n"
        "4 | White | Slate\n"
        "5 | Red | Blue\n"
        "6 | Red | Orange\n"
        "7 | Red | Green\n"
        "8 | Red | Brown\n"
        "9 | Red | Slate\n"
        "10 | Black | Blue\n"
        "11 | Black | Orange\n"
        "12 | Black | Green\n"
        "13 | Black | Brown\n"
        "14 | Black | Slate\n"
        "15 | Yellow | Blue\n"
        "16 | Yellow | Orange\n"
        "17 | Yellow | Green\n"
        "18 | Yellow | Brown\n"
        "19 | Yellow | Slate\n"
        "20 | Violet | Blue\n"
        "21 | Violet | Orange\n"
        "22 | Violet | Green\n"
        "23 | Violet | Brown\n"
        "24 | Violet | Slate\n";
    assert(actualManual == expectedConsoleBuffer);
    std::cout << "correct\n";
    return 0;
}
