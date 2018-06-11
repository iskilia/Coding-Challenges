//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"
Complex operator+ (const Complex& a, const Complex& b) {
    Complex result;
    result.a = a.a + b.a;
    result.b = a.b + b.b;
    return result;
}

ostream& operator<<(ostream& os, const Complex& c) {
    return os << c.a << (c.b > 0 ? '+' : '-') << 'i' << c.b;
}
