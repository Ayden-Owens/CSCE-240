/*
 * OOGeometricPropertyCalculator.cpp
 *
 *  Created on: Feb 9, 2022
 *      Author: Aweso
 */

#include "./Shapes.h"
#include "./Rectangle.h"
#include "./Circle.h"
#include "./Triangle.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream file;
    file.open("input.txt", ios::in);

    if(file.is_open()){
        cout<<" File open successfully "<<endl;
    }
    else{
        cout<<" File didn't open pls try again "<<endl;
    }
    string line;
    int num1=0, num2=0, num3=0;
    while(getline(file, line)){
        file>>num1>>num2>>num3;
    }
    file.close();
    cout<<"\n"<< " Please enter 1 for Area or 2 for Perimeter" << endl;
    int answer;
    cin >> answer;

    Circle cir;//obj of circle
    Triangle tri;
    Rectangle rec;
    Shapes s;

    //Area Section
    if (answer == 1){
        ofstream oFile;
        oFile.open("output.txt", ios::out);
        if (line == "circle"||line == "Circle"||line=="CIRCLE"){
            double a = cir.getArea(num1, num2, num3);
            oFile<<" Area of the Circle is "<<a<<endl;
            oFile.close();
        }
        else if (line == "triangle"||line == "Triangle" ||line=="TRIANGLE"){
            //s.getErrorMessage();
        	double a = tri.getArea(num1, num2, num3);
        	oFile<<" Area of the Triangle is "<<a<<endl;
            oFile.close();
        }
        else if (line == "rectangle"||line=="Rectangle"||line=="RECTANGLE	"){
            double a = rec.getArea(num1, num2, num3);
            oFile<<" Area of the Rectangle is "<<a<<endl;
            oFile.close();
        }
        else{
            s.getErrorMessage();
            cout<<"Please enter circle, triangle, rectangle in the input file!"<<endl;
            oFile.close();
        }
    }
    //Perimeter Section
    else if (answer == 2){
        ofstream oFile;
        oFile.open("output.txt", ios::out);
        if (line == "circle"){
            double p = cir.getPerimeter(num1, num2, num3);
            oFile<<" Perimeter of the Circle is "<<p<<endl;
            oFile.close();
        }
        else if (line == "triangle"){
            double p = tri.getPerimeter(num1, num2, num3);
            oFile<<" Perimeter of the triangle is "<<p<<endl;
            oFile.close();
        }
        else if (line == "rectangle"){
            double p = rec.getPerimeter(num1, num2, num3);
            oFile<<" Perimeter of the Circle is "<<p<<endl;
            oFile.close();
        }
        else {
             s.getErrorMessage();
             oFile.close();
        }
    }
    else{
    	cout<<"Please type triangle, circle, or rectangle in all lowercase with numbers after to properly compute!"<<endl;
    }
}


