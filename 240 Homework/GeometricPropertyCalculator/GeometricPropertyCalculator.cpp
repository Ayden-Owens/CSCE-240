/*
 * GeometricPropertyCalculator.cpp
 *
 *  Created on: Jan 26, 2022
 *      Author: Aweso
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	string filename;//makes a string response
	double sum;

	ifstream file;//this basically creates a constructor called file of the fstream class
	file.open("input.txt", ios::in);//opens file named input
	string line;
	string shape;
	int num1, num2, num3;
	while (getline(file, line)){
		file>>num1>>num2>>num3;
	}
	file.close();
	cout << "please enter 1 for Area or 2 for Perimeter" << endl;
	int ans;
	cin >> ans;
	//Area Section
	if (ans == 1){//start of area check
		ofstream oFile;
		oFile.open("output.txt");
		if (line == "triangle"){
			cout << "Can't calculate sorry" << endl;
			oFile << "Can't calculate sorry" << endl;
		}
		else if (line == "circle"){
			sum = 3.14*num1*num1;
			oFile << "Circle area is " << sum <<std::endl;
			oFile.close();
		}
		else if (line == "rectangle"){
			sum = num1*num2;
			oFile << "Rectangle area is " << sum <<std::endl;
			oFile.close();
		}
		else{
			cout << " please enter type in triangle, rectangle, or circle. " << endl;
			cout << " please enter 3 numbers for triangle, 2 for rectangle, and 1 for circle. " <<endl;
			oFile.close();
		}
	}//end of area check

	//Perimeter Section
	else if (ans == 2){
		ofstream oFile;
		oFile.open("output.txt");
		if (line == "triangle"){
			sum = num1+num2+num3;
	    	oFile << "Triangle perimeter is " << sum <<std::endl;
	    	oFile.close();
	    }
		else if (line == "circle"){
			sum = 2*3.14*num1;
			oFile << "Circle perimeter is " << sum <<std::endl;
			oFile.close();
		}
		else if (line == "rectangle"){
			sum = 2*(num1+num2);
			oFile << "Rectangle perimeter is " << sum <<std::endl;
			oFile.close();
		}
		else{
			cout << " please enter type in triangle, rectangle, or circle" <<endl;
			cout << " please enter 3 numbers for triangle, 2 for rectangle, and 1 for circle. " <<endl;
			oFile.close();
		}
	}

}



