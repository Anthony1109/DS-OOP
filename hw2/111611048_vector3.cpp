#include <iostream>
#include "111611048_vector3.h"
#include <cmath>

using namespace std;

vector3::vector3(double x, double y, double z): x(x), y(y), z(z) {}

vector3::vector3(const vector3& v): x(v.x), y(v.y), z(v.z) {}

vector3 vector3::operator+(const vector3& v){
    return vector3(x + v.x, y + v.y, z + v.z);
}

vector3 vector3::operator-(const vector3& v){
    return vector3(x - v.x, y - v.y, z - v.z);
}

vector3 vector3::operator*(double k){
    return vector3(x * k, y * k, z * k);
}

vector3 vector3::operator/(double k){
    return vector3(x / k, y / k, z / k);
}

vector3 operator*(double k, const vector3& v){
    return vector3(v.x * k, v.y * k, v.z * k);
}

vector3 operator/(double k, const vector3& v){
    return vector3(v.x / k, v.y / k, v.z / k);
}

vector3 operator-(const vector3& v){
    return vector3(-v.x, -v.y, -v.z);
}

bool vector3::operator==(const vector3& v){
    return x == v.x && y == v.y && z == v.z;
}

bool vector3::operator!=(const vector3& v){
    return x != v.x || y != v.y || z != v.z;
}

vector3& vector3::operator+=(const vector3& v){
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

vector3& vector3::operator-=(const vector3& v){
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

vector3& vector3::operator*=(double k){
    x *= k;
    y *= k;
    z *= k;
    return *this;
}

vector3& vector3::operator/=(double k){
    x /= k;
    y /= k;
    z /= k;
    return *this;
}

double vector3::length(){
    return sqrt(x*x + y*y + z*z);
}

void vector3::printVector3(){
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}

double& vector3::operator[](int index){
    if(index == 0)
        return x;
    else if(index == 1)
        return y;
    else
        return z;
}

const double& vector3::operator[](int index) const{
    if(index == 0)
        return x;
    else if(index == 1)
        return y;
    else
        return z;
}