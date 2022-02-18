/*
 * Triangle.cpp
 *
 *  Created on: Feb 9, 2022
 *      Author: Aweso
 */

#include "./Triangle.h"
#include <iostream>
#include <string>
using namespace std;

Triangle::Triangle(){
    shape="triangle";
}
Triangle::~Triangle(){
}

double Triangle::getArea(double num1, double num2, double num3){
	Shapes::getArea(num1,num2,num3);
	return area;
}

double Triangle::getPerimeter(double num1, double num2, double num3){
	Shapes::getPerimeter(num1,num2,num3);
	return perimeter;
}

void Triangle::getErrorMessage(){
	Shapes::getErrorMessage();
}


