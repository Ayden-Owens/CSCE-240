/*
 * Circle.cpp
 *
 *  Created on: Feb 9, 2022
 *      Author: Aweso
 */

#include "./Circle.h"
#include <iostream>
#include <string>

using namespace std;

Circle::Circle(){
    shape = "circle";
}

Circle::~Circle(){
}

double Circle::getArea(double num1, double num2, double num3){
    Shapes::getArea(num1, num2, num3);
    return area;
}

double Circle::getPerimeter(double num1, double num2, double num3){
    Shapes::getPerimeter(num1,num2,num3);
    return perimeter;
}

void Circle::getErrorMessage(){
    Shapes::getErrorMessage();
}


