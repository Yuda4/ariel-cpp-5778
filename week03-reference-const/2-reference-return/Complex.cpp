/**
 * Demonstrates returning references from functions to create chain of calls.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-03
 */

#include <iostream>
using namespace std;

class Complex {
    double _re, _im;

public:
    Complex() {  _re = _im  = 0; }    // inline constructor

    double real() const {  // getter
        cout << "real const" << endl;
        return _re;
    }

    double& real() {       // setter
        cout << "real non-const" << endl;
        return _re;
    }

    Complex& setReal(double r) { 
        _re = r; 
        return *this;
    }

    Complex& setImag(double i) { 
        _im = i; 
        return *this;
    }

    Complex& add (const Complex& c) {
        _re += c._re;
        _im += c._im;
        return *this;
    }

    string to_string() {           // inline method  
        return std::to_string(_re)+"+"+std::to_string(_im)+"i";
    }
};


int main() {
    Complex a;
    a.real() = 5;
    cout << a.real() << endl;

    const Complex c;
    //c.real() = 5;
    cout << c.real() << endl;

    cout << a.to_string() << endl;
    a.setReal(1).setImag(2);
    cout << a.to_string() << endl;
    Complex b = a;
    a.add(Complex().setReal(3).setImag(4)).add(b);
    cout << a.to_string() << endl;
    return 0;
}
