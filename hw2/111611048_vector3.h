#include <iostream>

class vector3{
public:
    vector3(double x = 0, double y = 0, double z = 0);
    vector3(const vector3& v);
    vector3 operator+(const vector3& v);
    vector3 operator-(const vector3& v);
    vector3 operator*(double k);
    vector3 operator/(double k);

    friend vector3 operator*(double k, const vector3& v);
    friend vector3 operator/(double k, const vector3& v);
    friend vector3 operator-(const vector3& v);

    bool operator==(const vector3& v);
    bool operator!=(const vector3& v);
    vector3& operator+=(const vector3& v);
    vector3& operator-=(const vector3& v);
    vector3& operator*=(double k);
    vector3& operator/=(double k);

    double length();
    void printVector3();

    double& operator[](int index);
    const double& operator[](int index) const;
private:
    double x, y, z;
};
