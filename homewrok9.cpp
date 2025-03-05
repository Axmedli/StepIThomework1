#include <iostream>
#include <cassert>
#include <windows.h>

using namespace std;

class Fraction {
private:
    int _numerator;
    int _denominator;

public:
    Fraction(int num, int den) {
        _numerator = num;
        _denominator = den;
        assert(_denominator != 0 && "Error: mexrec 0 ola bilmez.");
    }

    Fraction Multiply(const Fraction& other) {
        return Fraction(_numerator * other._numerator, _denominator * other._denominator);
    }

    Fraction Add(const Fraction& other) {
        int num = _numerator * other._denominator + other._numerator * _denominator;
        int den = _denominator * other._denominator;
        return Fraction(num, den);
    }

    Fraction Minus(const Fraction& other) {
        int num = _numerator * other._denominator - other._numerator * _denominator;
        int den = _denominator * other._denominator;
        return Fraction(num, den);
    }

    Fraction Divide(const Fraction& other) {
        return Fraction(_numerator * other._denominator, _denominator * other._numerator);
    }

    void Print() {
        cout << _numerator << "/" << _denominator << endl;
    }
};


class Counter {
private:
    int _min;
    int _max;
    int _currentValue;
public:
    Counter(int min, int max) {
        _min = min;
        _max = max;
        _currentValue = min;
    }

    void increment() {
        if (_currentValue == _max)
            _currentValue = _max;
        else
            _currentValue++;
    }
    
    void decrement() {
        if (_currentValue == _max)
            _currentValue = _max;
        else
            _currentValue--;

    }


    int getCurrent() const {
        return _currentValue;
    }
};

/*

int main() {
    Fraction f1(4, 7);
    Fraction f2(4, 7);
    Fraction result = f1.Multiply(f2);
    Fraction result2 = f1.Add(f2);
    Fraction result3 = f1.Minus(f2);
    Fraction result4 = f1.Divide(f2);

    cout << "Multiply: ";
    result.Print();
    cout << "Add: ";
    result2.Print();
    cout << "Minus: ";
    result3.Print();
    cout << "Divide: ";
    result4.Print();

    return 0;
}

*/


int main() {
    int max = 100;
    int min = 0;
    Counter c(min, max);

    
    while (min<=max) {
        system("cls || clear"); 
        cout << "*************************" << endl;
        cout << "*                       *" << endl;
        cout << "*           "<< c.getCurrent() << "\t\t*" << endl;
        cout << "*                       *" << endl;
        cout << "*************************" << endl;
        c.increment();
        Sleep(1000);
        ++min;
    }
    

    /*
    max = 0;
    min = 100;
    while (max <= min) {
        system("cls || clear");
        cout << "*************************" << endl;
        cout << "*                       *" << endl;
        cout << "*           " << c.getCurrent() << "\t\t*" << endl;
        cout << "*                       *" << endl;
        cout << "*************************" << endl;
        c.decrement();
        Sleep(1000);
        --min;
    }

    */

    return 0;
}
