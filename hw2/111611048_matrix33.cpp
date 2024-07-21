#include <iostream>
#include "111611048_matrix33.h"
#include <cmath>
#include <iomanip>

using namespace std;

matrix33::matrix33(vector3 v1, vector3 v2, vector3 v3) :v1(v1), v2(v2), v3(v3) {}

matrix33::matrix33(const matrix33& m): v1(m.v1), v2(m.v2), v3(m.v3) {}

matrix33 matrix33::operator+(const matrix33& m){
    return matrix33(v1 + m.v1, v2 + m.v2, v3 + m.v3);
}

matrix33 matrix33::operator-(const matrix33& m){
    return matrix33(v1 - m.v1, v2 - m.v2, v3 - m.v3);
}

matrix33 matrix33::operator*(double k){
    return matrix33(v1 * k, v2 * k, v3 * k);
}

matrix33 matrix33::operator/(double k){
    return matrix33(v1 / k, v2 / k, v3 / k);
}

matrix33 operator*(double k, const matrix33& m){
    return matrix33(k * m.v1, k * m.v2, k * m.v3);
}

matrix33 operator/(double k, const matrix33& m){
    return matrix33(k / m.v1, k / m.v2, k / m.v3);
}

matrix33 operator-(const matrix33& m){
    return matrix33(-m.v1, -m.v2, -m.v3);
}

matrix33 matrix33::operator*(const matrix33& m){
    matrix33 result;     
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result[i][j] = m[i][0] * v1[j] + m[i][1] * v2[j] + m[i][2] * v3[j];
        }    
    }   
    
    return result;
}

bool matrix33::operator==(const matrix33& m){
    return v1 == m.v1 && v2 == m.v2 && v3 == m.v3;
}

bool matrix33::operator!=(const matrix33& m){
    return v1 != m.v1 || v2 != m.v2 || v3 != m.v3;
}

matrix33& matrix33::operator+=(const matrix33& m){
    v1 += m.v1;
    v2 += m.v2;
    v3 += m.v3;
    return *this;
}

matrix33& matrix33::operator-=(const matrix33& m){
    v1 -= m.v1;
    v2 -= m.v2;
    v3 -= m.v3;
    return *this;
}

matrix33& matrix33::operator*=(double k){
    v1 *= k;
    v2 *= k;
    v3 *= k;
    return *this;
}

matrix33& matrix33::operator/=(double k){
    v1 /= k;
    v2 /= k;
    v3 /= k;
    return *this;
}

void matrix33::printMatrix(){
    cout << setw(4) << v1[0] << " " << setw(4) << v2[0] << " " << setw(4) << v3[0] << endl;
    cout << setw(4) << v1[1] << " " << setw(4) << v2[1] << " " << setw(4) << v3[1] << endl;
    cout << setw(4) << v1[2] << " " << setw(4) << v2[2] << " " << setw(4) << v3[2] << endl;
}

matrix33 matrix33::invert(){
    double det = determinant();
    if(det == 0){
        cout << "Matrix is not invertible" << endl;
    }
    vector3 row1 = {v2[1]*v3[2] - v2[2]*v3[1], v1[2]*v3[1] - v1[1]*v3[2], v1[1]*v2[2] - v1[2]*v2[1]};
    vector3 row2 = {v2[2]*v3[0] - v2[0]*v3[2], v1[0]*v3[2] - v1[2]*v3[0], v1[2]*v2[0] - v1[0]*v2[2]};
    vector3 row3 = {v2[0]*v3[1] - v2[1]*v3[0], v1[1]*v3[0] - v1[0]*v3[1], v1[0]*v2[1] - v1[1]*v2[0]};
    matrix33 adj = matrix33(row1, row2, row3);
    return  adj / det;
}



void matrix33::identity(){
    v1 = vector3(1, 0, 0);
    v2 = vector3(0, 1, 0);
    v3 = vector3(0, 0, 1);
}

int matrix33::determinant(){
    return v1[0]*(v2[1]*v3[2] - v2[2]*v3[1]) - v1[1]*(v2[0]*v3[2] - v2[2]*v3[0]) + v1[2]*(v2[0]*v3[1] - v2[1]*v3[0]);
}


vector3& matrix33::operator[](int index){
    if(index == 0)
        return v1;
    else if(index == 1)
        return v2;
    else
        return v3;
}

const vector3& matrix33::operator[](int index) const{
    if(index == 0)
        return v1;
    else if(index == 1)
        return v2;
    else
        return v3;
}



