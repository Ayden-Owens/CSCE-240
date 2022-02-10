/*
 * Circle.h
 *
 *  Created on: Feb 9, 2022
 *      Author: Aweso
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shapes.h"
#include <iostream>
#include <string>
using namespace std;

class Circle: public Shapes{
    public:
    Circle();
    double getArea(double num1, double num2, double num3);
    double getPerimeter(double num1, double num2, double num3);
    void getErrorMessage();
    ~Circle();
};



#endif /* CIRCLE_H_ */
