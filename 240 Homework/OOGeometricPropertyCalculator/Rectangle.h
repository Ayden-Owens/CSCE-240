/*
 * Rectangle.h
 *
 *  Created on: Feb 9, 2022
 *      Author: Aweso
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shapes.h"
#include <iostream>
#include <string>
using namespace std;

class Rectangle: public Shapes{
    public:
    Rectangle();
    double getArea(double num1, double num2, double num3);
    double getPerimeter(double num1, double num2, double num3);
    void getErrorMessage();
    ~Rectangle();
};



#endif /* RECTANGLE_H_ */
