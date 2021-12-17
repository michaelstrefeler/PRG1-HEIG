#include <iostream>
#include <iomanip>

using namespace std;
/**
 * @brief C class with a data attribute
 *
 */
class C
{
    int data;
    public: 
    C() : data(0){};              // Default constructor. Sets data to 0
    C(int value) : data(value){}; // Constructor
    friend ostream &operator<<(ostream &left, const C &right);
    bool operator==(const C &right) const
    {
        return this->data == right.data;
    }
    bool operator!=(const C &right)
    {
        return !(*this == right);
    }
    C operator++() // Prefix increment ++data
    {
        ++data;
        return *this;
    }
    C operator++(int) // Postfix increment data++
    {   C temp = *this;
        ++*this;
        return temp;
    }
    C& operator+=(const C& right){
        data += right.data;
        return *this;
    }

    friend C operator+(C left, const C& right){
        left += right;
        return left;
    }
};

/**
 * @brief Overloading << operator to output the class data
 *
 * @param left left hand side of the << operator (ostream)
 * @param right right hand side of the << operator (C class)
 * @return ostream&
 */
ostream &operator<<(ostream &left, const C& right)
{
    left << right.data; // this is accessible stop complaining VSCode
    return left;
}

int main()
{
    C c0, c1(1), c2 = 5;
    const C C3{7};
    cout << c0 << endl
         << c1 << endl;
    cout << boolalpha;
    cout << (c0 == c1) << endl;
    cout << (c0 != c1) << endl;
    cout << noboolalpha;
    cout << c1++ << endl;
    cout << c1 << endl;
    cout << ++c1 << endl;
    cout << c1 + c2 << endl;
    c1 += c2;
    cout << c1 << endl;
    cout << C3 + c2 << endl;
}