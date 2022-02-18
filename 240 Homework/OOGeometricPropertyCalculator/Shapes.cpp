/*
 * Shapes.cpp
 *
 *  Created on: Feb 9, 2022
 *      Author: Aweso
 */

#include "Shapes.h"
#include <iostream>
#include <string>

using namespace std;

Shapes::~Shapes(){}//deconstuctor

Shapes::Shapes(){
    shape = " no shape ";
}

Shapes::Shapes(string line){
    shape = line;
}

string Shapes::getShapes(){
    return shape;
}

void Shapes::setShapes(string line){
    shape = line;
}

double Shapes::getArea(double num1, double num2, double num3){
    if(getShapes()=="triangle"){
        //getErrorMessage();
    	area = (num1*num2)/2;
    }
    else if (getShapes() == "circle"){
        area = 3.14*num1*num1;
    }
    else if (getShapes() == "rectangle"){
        area = num1*num2;
    }
    else {
        getErrorMessage();
    }
    return area;
}

double Shapes::getPerimeter(double num1, double num2, double num3){
    if(getShapes() == "triangle"){
    	if (num1==0||num2==0||num3==0){
    		getErrorMessage();
    		cout<<" please enter 3 numbers on each "<<endl;
    	}
        perimeter = num1 + num2 + num3;
    }
    else if (getShapes() == "circle"){
        perimeter = 2*3.14*num1;
    }
    else if (getShapes() == "rectangle"){

        perimeter = 2*(num1+num2);
    }
    else {
        getErrorMessage();
    }
    return perimeter;
}

void Shapes::getErrorMessage(){
    cout<< " Could not compute! " <<endl;
}



