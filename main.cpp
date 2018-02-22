#include <math.h>
#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include "gradient.h"



using namespace std;

double dot(vector<double>, vector<double>);
vector<double> createVec(double, double);
vector<double> createUnitVec(vector<double> );
vector<double> createGradient(double, double);



int main(){
	cout << "Welcome to the directional derivative calculator. If you haven't already, change the contents of the gradient.h file locally to suit your problem." << endl;
	//gradient vector at x=2, y=2
	cout << "Enter (a,b): ";
	//point in space
	double a,b;
	//Direction of derivative
	double Dx,Dy;

	cin >> a >> b;
	cout << endl;
	cout << "Enter direction of derivative: ";
	cin >> Dx >> Dy;	
	auto DirectionVector = createUnitVec(createVec(Dx,Dy));

	auto gradient = createGradient(a,b);
	auto maxIncrease = dot(gradient, DirectionVector);
	cout << "The steepest rate of increase is: " << maxIncrease << " at the point (" << a << "," << b << ")" << endl;
}

//creates a gradient vector of a and b given Fx and Fy represent partial derivatives of your function
vector<double> createGradient(double a, double b){
	std::vector<double> vec = {Fx(a,b),Fy(a,b)};
	return vec;
}

double magnitude(vector<double> vec){
	int sum = 0;
	for(int i = 0; i < vec.size(); i++){
		sum += pow(vec[i],2);
	}
	return sqrt(sum);
}

//creates a unit vector in the direction of <a,b>
vector<double> createUnitVec(vector<double> vec){
	double mag = magnitude(vec);

	for(int i = 0; i < vec.size(); i++){
		vec[i]/=mag;
	}

	return vec;
}

//creates a vector of a and b
vector<double> createVec(double a, double b){
	std::vector<double> vec = {a,b};
	return vec;
}

double dot(vector<double> v1, vector<double> v2){
	if(v1.size() != v2.size() || (v1.size() == 0 || v2.size() == 0)){
		return 0;
	}
	int sum = 0;
	for(int i = 0; i < v1.size(); i++){
		sum += (v1[i]*v2[i]);
	}
	return sum;
} 
