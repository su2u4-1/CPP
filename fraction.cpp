#include <iostream>
#include <numeric>
#include <string>
using namespace std;

class Fraction {
   private:
    int numer;
    int denom;
    void normalize() {
        int g = gcd(numer, denom);
        numer /= g;
        denom /= g;
        if (denom < 0) {
            numer = -numer;
            denom = -denom;
        }
    }

   public:
    // initializers
    Fraction(int a, int b) {
        numer = a;
        denom = b;
        normalize();
    }
    Fraction(int a) {
        numer = a;
        denom = 1;
    }
    Fraction() {
        numer = 0;
        denom = 1;
    }
    Fraction(const Fraction& other) {
        numer = other.numer;
        denom = other.denom;
    }
    Fraction(double a, double b) {
        while (a != (int)a) {
            a *= 10;
            b *= 10;
        }
        while (b != (int)b) {
            a *= 10;
            b *= 10;
        }
        numer = (int)a;
        denom = (int)b;
        normalize();
    }
    Fraction(double a, int b) {
        while (a != (int)a) {
            a *= 10;
            b *= 10;
        }
        numer = (int)a;
        denom = (int)b;
        normalize();
    }
    Fraction(int a, double b) {
        while (b != (int)b) {
            a *= 10;
            b *= 10;
        }
        numer = (int)a;
        denom = (int)b;
        normalize();
    }
    Fraction(double a) {
        while (a != (int)a) {
            a *= 10;
        }
        numer = (int)a;
        denom = 1;
        normalize();
    }
    Fraction(Fraction& a, int b) {
        numer = a.numer * a.denom;
        denom = b * a.denom;
        normalize();
    }
    Fraction(int a, Fraction& b) {
        numer = a * b.denom;
        denom = b.numer * b.denom;
        normalize();
    }
    Fraction(Fraction& a, double b) {
        while (b != (int)b) {
            b *= 10;
        }
        numer = a.numer * a.denom;
        denom = (int)b * a.denom;
        normalize();
    }
    Fraction(double a, Fraction& b) {
        while (a != (int)a) {
            a *= 10;
        }
        numer = (int)a * b.denom;
        denom = b.numer * b.denom;
        normalize();
    }
    // others
    ~Fraction() {}
    int to_int() {
        return numer / denom;
    }
    double to_double() {
        return (double)numer / denom;
    }
    string to_str() {
        return to_string(numer) + "/" + to_string(denom);
    }
    // overloaded operators
    // + - * / % ^ & | ~ ! = < > += -= *= /= %= ^= &= |= << >> >>= <<= == != <= >= && || ++ -- , ->* -> () []
    Fraction operator+(Fraction other) {
        return Fraction(numer * other.denom + other.numer * denom, denom * other.denom);
    }
    Fraction operator+(int other) {
        return Fraction(numer + other * denom, denom);
    }
    Fraction operator+(double other) {
        while (other != (int)other) {
            other *= 10;
            numer *= 10;
        }
        return Fraction(numer + (int)other * denom, denom);
    }
    Fraction operator-(Fraction other) {
        return Fraction(numer * other.denom - other.numer * denom, denom * other.denom);
    }
    Fraction operator-(int other) {
        return Fraction(numer - other * denom, denom);
    }
    Fraction operator-(double other) {
        while (other != (int)other) {
            other *= 10;
            numer *= 10;
        }
        return Fraction(numer - (int)other * denom, denom);
    }
    Fraction operator*(Fraction other) {
        return Fraction(numer * other.numer, denom * other.denom);
    }
    Fraction operator*(int other) {
        return Fraction(numer * other, denom);
    }
    Fraction operator*(double other) {
        while (other != (int)other) {
            other *= 10;
            numer *= 10;
        }
        return Fraction(numer * (int)other, denom);
    }
    Fraction operator/(Fraction other) {
        return Fraction(numer * other.denom, denom * other.numer);
    }
    Fraction operator/(int other) {
        return Fraction(numer, denom * other);
    }
    Fraction operator/(double other) {
        while (other != (int)other) {
            other *= 10;
            denom *= 10;
        }
        return Fraction(numer, denom * (int)other);
    }
    Fraction operator%(Fraction other) {
        return Fraction(numer * other.denom % (denom * other.numer), denom * other.denom);
    }
    Fraction operator%(int other) {
        return Fraction(numer % (denom * other), denom);
    }
    Fraction operator%(double other) {
        while (other != (int)other) {
            other *= 10;
            denom *= 10;
        }
        return Fraction(numer % (denom * (int)other), denom);
    }
    Fraction operator^(Fraction other) {
        return Fraction(numer ^ other.numer, denom ^ other.denom);
    }
    Fraction operator^(int other) {
        return Fraction(numer ^ other, denom ^ 1);
    }
    Fraction operator^(double other) {
        while (other != (int)other) {
            other *= 10;
            denom *= 10;
        }
        return Fraction(numer ^ (int)other, denom ^ 1);
    }
    Fraction operator&(Fraction other) {
        return Fraction(numer & other.numer, denom & other.denom);
    }
    Fraction operator&(int other) {
        return Fraction(numer & other, denom & 1);
    }
    Fraction operator&(double other) {
        while (other != (int)other) {
            other *= 10;
            denom *= 10;
        }
        return Fraction(numer & (int)other, denom & 1);
    }
    Fraction operator|(Fraction other) {
        return Fraction(numer | other.numer, denom | other.denom);
    }
    Fraction operator|(int other) {
        return Fraction(numer | other, denom | 1);
    }
    Fraction operator|(double other) {
        while (other != (int)other) {
            other *= 10;
            denom *= 10;
        }
        return Fraction(numer | (int)other, denom | 1);
    }
    Fraction operator~() {
        return Fraction(~numer, ~denom);
    }
    Fraction operator!() {
        return Fraction(denom, numer);
    }
};

int main() {
}
