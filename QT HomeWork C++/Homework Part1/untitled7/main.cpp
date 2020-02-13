#include <iostream>

using namespace std;

class Record
{
public:
    void printArrayOfSymbols();
    void deleteSymbolByNumber();
    void deleteSymbolByValue();
private:
    class Symbol
    {
    public:
        Symbol();
        void printSymbol();
        char returnValueSymbol();
    };
    char symbol;
    Symbol arrayOfSymbols [15];
};

void Record::deleteSymbolByValue()
{

}

void Record::deleteSymbolByNumber()
{

}

void Record::printArrayOfSymbols()
{

}

int main()
{
    Record obj1;

    return 0;
}
