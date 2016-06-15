#pragma once
#include <iostream>
#include <fstream>  //file stream
#include <ctime>    //system time
#include <cstdlib>
#include <math.h>   //math information header
#include <sstream>  //string stream
#include <stdlib.h> //standard library
#include <time.h>   //time information header
#include <sys/types.h>  //system types headers
#include <fcntl.h>  //file open header
#include <stdio.h>  //standard input output
#include <string>   //string library
#include <vector>   //Allows for vectors
using namespace std;

class atom {
public:
	int
		id_, mol_, type_;
	double
		Q_, //charge
		X_, Y_, Z_, //xyz coords
		cX_, cX0_, cY_, cY0_, cZ_, cZ0_, //center of mass coords
		eX_, eX0_, eY_, eY0_, eZ_, eZ0_, //normalized dipole moment vector
		mux_, mux0_, muy_, muy0_, muz_, muz0_, //dipole moment vector
		M_; //molar mass
	string
		name_;


};

class diffusion {
public:
	vector<double> av_, sdv_;
	vector<int> N_;
	vector<double> av_val_;
};

class reorientation {
public:
	vector<double> c1av_, c1sdv_, c2av_, c2sdv_;
	vector<int> c1N_, c2N_;
	vector<double> c1val_, c2val_;
};