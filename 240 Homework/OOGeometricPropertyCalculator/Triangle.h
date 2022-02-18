/*
 * Triangle.h
 *
 *  Created on: Feb 9, 2022
 *      Author: Aweso
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shapes.h"
#include <iostream>
#include <string>
using namespace std;

class Triangle : public Shapes{
    public:
    Triangle();
    double getArea(double num1, double num2, double num3);
    double getPerimeter(double num1, double num2, double num3);
    void getErrorMessage();
    ~Triangle();
};



#endif /* TRIANGLE_H_ */
