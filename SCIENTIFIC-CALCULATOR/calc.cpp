#include<iostream>
#include<cmath>
#include<process.h>
#include<string>
using namespace std;

char Numbers[] = "0123456789ABCDEFGHIJ";

class Fraction {
private:
    double num, den;
public:
    Fraction() : num(0), den(1) {}
    void getFraction() {
        char ch;
        cout << "Enter fraction (n/m): ";
        cin >> num >> ch >> den;
        while (den == 0) {
            cout << "Denominator cannot be zero. Enter fraction (n/m): ";
            cin >> num >> ch >> den;
        }
    }
    void print() {
        cout << "Result: " << num << "/" << den << endl;
    }
    void sum(Fraction f1, Fraction f2) {
        num = (f1.num * f2.den) + (f1.den * f2.num);
        den = f1.den * f2.den;
    }
    void sub(Fraction f1, Fraction f2) {
        num = (f1.num * f2.den) - (f1.den * f2.num);
        den = f1.den * f2.den;
    }
    void multiply(Fraction f1, Fraction f2) {
        num = f1.num * f2.num;
        den = f1.den * f2.den;
    }
    void divide(Fraction f1, Fraction f2) {
        num = f1.num * f2.den;
        den = f1.den * f2.num;
    }
};

class Complex {
private:
    double real, image;
public:
    Complex() : real(0), image(0) {}
    void getComplex() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> image;
    }
    void print() {
        cout << "Result: " << real << " + " << image << "i" << endl;
    }
    void sum(Complex c1, Complex c2) {
        real = c1.real + c2.real;
        image = c1.image + c2.image;
    }
    void sub(Complex c1, Complex c2) {
        real = c1.real - c2.real;
        image = c1.image - c2.image;
    }
    void multiply(Complex c1, Complex c2) {
        real = (c1.real * c2.real) - (c1.image * c2.image);
        image = (c1.real * c2.image) + (c1.image * c2.real);
    }
    void divide(Complex c1, Complex c2) {
        double den = (c2.real * c2.real) + (c2.image * c2.image);
        real = ((c1.real * c2.real) + (c1.image * c2.image)) / den;
        image = ((c1.image * c2.real) - (c1.real * c2.image)) / den;
    }
};

void absoluteValue() {
    int x;
    char ch;
    do {
        cout << "Enter a number: ";
        cin >> x;
        cout << "Absolute value: " << abs(x) << endl;
        cout << "Repeat? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

unsigned long factorial(int num) {
    unsigned long fact = 1;
    for (int i = 1; i <= num; i++) fact *= i;
    return fact;
}

void power() {
    double base, exponent;
    char ch;
    do {
        cout << "Enter base and exponent: ";
        cin >> base >> exponent;
        cout << "Result: " << pow(base, exponent) << endl;
        cout << "Repeat? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void arithmeticOperation() {
    float num1, num2, result;
    char op, ch;
    do {
        cout << "Enter operation (n op m): ";
        cin >> num1 >> op >> num2;
        switch (op) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/': 
                if (num2 == 0) cout << "Division by zero error.\n";
                else result = num1 / num2;
                break;
            default: cout << "Invalid operation.\n";
        }
        cout << "Result: " << result << endl;
        cout << "Repeat? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void fractionOperation() {
    Fraction f1, f2;
    int choice;
    char ch;
    do {
        f1.getFraction();
        f2.getFraction();
        cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: f1.sum(f1, f2); break;
            case 2: f1.sub(f1, f2); break;
            case 3: f1.multiply(f1, f2); break;
            case 4: f1.divide(f1, f2); break;
            default: cout << "Invalid choice.\n";
        }
        f1.print();
        cout << "Repeat? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void complexOperation() {
    Complex c1, c2;
    int choice;
    char ch;
    do {
        c1.getComplex();
        c2.getComplex();
        cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: c1.sum(c1, c2); break;
            case 2: c1.sub(c1, c2); break;
            case 3: c1.multiply(c1, c2); break;
            case 4: c1.divide(c1, c2); break;
            default: cout << "Invalid choice.\n";
        }
        c1.print();
        cout << "Repeat? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void quadraticEquation() {
    int a, b, c;
    double x1, x2;
    char ch;
    do {
        cout << "Enter coefficients a, b, c: ";
        cin >> a >> b >> c;
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            cout << "No real roots.\n";
        } else {
            x1 = (-b + sqrt(discriminant)) / (2 * a);
            x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Roots: " << x1 << ", " << x2 << endl;
        }
        cout << "Repeat? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void squareRoot() {
    double x;
    char ch;
    do {
        cout << "Enter a number: ";
        cin >> x;
        if (x < 0) cout << "Invalid input.\n";
        else cout << "Square root: " << sqrt(x) << endl;
        cout << "Repeat? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void triangleFunctions() {
    double x;
    int choice;
    char ch;
    do {
        cout << "1. Sin\n2. Cos\n3. Tan\nChoice: ";
        cin >> choice;
        cout << "Enter angle: ";
        cin >> x;
        x = x * 0.01745329252; // Convert to radians
        switch (choice) {
            case 1: cout << "Sin: " << sin(x) << endl; break;
            case 2: cout << "Cos: " << cos(x) << endl; break;
            case 3: cout << "Tan: " << tan(x) << endl; break;
            default: cout << "Invalid choice.\n";
        }
        cout << "Repeat? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void logarithm() {
    double x;
    int choice;
    char ch;
    do {
        cout << "1. Natural Log\n2. Base 10 Log\nChoice: ";
        cin >> choice;
        cout << "Enter number: ";
        cin >> x;
        switch (choice) {
            case 1: cout << "Ln: " << log(x) << endl; break;
            case 2: cout << "Log10: " << log10(x) << endl; break;
            default: cout << "Invalid choice.\n";
        }
        cout << "Repeat? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

string convert(int x, int base) {
    string ret;
    while (x) {
        ret = Numbers[x % base] + ret;
        x /= base;
    }
    return ret;
}

void convertSystems() {
    int x, base;
    char ch;
    do {
        cout << "Enter decimal number and base: ";
        cin >> x >> base;
        cout << "Converted: " << convert(x, base) << endl;
        cout << "Repeat? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void displayMenu() {
    while (true) {
        int choice;
        cout << "1. Absolute Value\n2. Factorial\n3. Power\n4. Arithmetic Operation\n5. Fraction Operation\n6. Complex Operation\n7. Quadratic Equation\n8. Square Root\n9. Triangle Functions\n10. Logarithm\n11. Convert Systems\n12. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: absoluteValue(); break;
            case 2: {
                int num;
                cout << "Enter number: ";
                cin >> num;
                cout << "Factorial: " << factorial(num) << endl;
                break;
            }
            case 3: power(); break;
            case 4: arithmeticOperation(); break;
            case 5: fractionOperation(); break;
            case 6: complexOperation(); break;
            case 7: quadraticEquation(); break;
            case 8: squareRoot(); break;
            case 9: triangleFunctions(); break;
            case 10: logarithm(); break;
            case 11: convertSystems(); break;
            case 12: exit(0);
            default: cout << "Invalid choice.\n";
        }
    }
}

int main() {
    displayMenu();
    return 0;
}