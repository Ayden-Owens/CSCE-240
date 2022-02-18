/*
 * Shapes.h
 *
 *  Created on: Feb 9, 2022
 *      Author: Aweso
 */

#ifndef SHAPES_H_
#define SHAPES_H_

#include <iostream>
#include <string>
using namespace std;

class Shapes {
    //functions I'm gonna call
    public:
        Shapes();//default constructor
        Shapes(string line);//parametized constructor
        string getShapes();//
        void setShapes(string line);
        void getErrorMessage();
        double getArea(double num1, double num2, double num3);
        double getPerimeter(double num1, double num2, double num3);
        virtual ~Shapes();
    protected:
        string shape;
        double area = 0;
        double perimeter = 0;
};

#endif /* SHAPES_H_ */
