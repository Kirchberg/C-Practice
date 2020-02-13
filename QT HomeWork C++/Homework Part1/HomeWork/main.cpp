#include <iostream>

using namespace std;

    class classOne
    {
    protected:
        int num;
    public:
        classOne()
        {
            num = 0;
        };
        void func()
        {
            num++; cout << num << '\n';
        };
    };

    class ClassTwo: public classOne
    {
    public:
        void func()
        {
            num--; cout << num << '\n';
        };
    };

    int main()
    {
        classOne *One = new classOne;
        classTwo *Two = new classTwo;
        One->func();
        Two->func();
        return 0;
    }
