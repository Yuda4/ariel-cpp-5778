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
    Complex(double re=0, double im=0): 
        _re(re),
        _im(im)
        {  }

    double real() const {  // getter
        cout << "real const" << endl;
        return _re;
    }

    double& real() {       // setter and getter
        cout << "real non-const" << endl;
        return _re;
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

    return 0;
}
