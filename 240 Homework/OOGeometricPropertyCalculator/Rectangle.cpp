/*
 * Rectangle.cpp
 *
 *  Created on: Feb 9, 2022
 *      Author: Aweso
 */

#include "./Rectangle.h"
#include <iostream>
#include <string>

using namespace std;

Rectangle::Rectangle(){
    shape = "rectangle";
}

Rectangle::~Rectangle(){
}

double Rectangle::getArea(double num1, double num2, double num3){
    Shapes::getArea(num1,num2,num3);
    return area;
}

double Rectangle::getPerimeter(double num1, double num2, double num3){
    Shapes::getPerimeter(num1,num2,num3);
    return perimeter;
}

void Rectangle::getErrorMessage(){
    Shapes::getErrorMessage();
}




