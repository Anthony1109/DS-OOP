#include "111611048_vector3.h"

class matrix33{
public:
    matrix33(vector3 v1 = vector3(), vector3 v2 = vector3(), vector3 v3 = vector3());
    matrix33(const matrix33& m);
    matrix33 operator+(const matrix33& m);
    matrix33 operator-(const matrix33& m);
    matrix33 operator*(double k);
    matrix33 operator/(double k);

    friend matrix33 operator*(double k, const matrix33& m);
    friend matrix33 operator/(double k, const matrix33& m);
    friend matrix33 operator-(const matrix33& m);

    matrix33 operator*(const matrix33& m1);

    bool operator==(const matrix33& m);
    bool operator!=(const matrix33& m);
    matrix33& operator+=(const matrix33& m);
    matrix33& operator-=(const matrix33& m);
    matrix33& operator*=(double k);
    matrix33& operator/=(double k);

    void printMatrix();
    matrix33 invert();
    void identity();
    int determinant();

    vector3& operator[](int index);
    const vector3& operator[](int index) const;
private:    
    vector3 v1, v2, v3;
};
