#pragma once
#include "Spline.h"
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numbers>

void firstTest() { // constant function
	std::cout << "___________________________________________________________________________________________";
	std::cout << "\nFirst test: \n";
	bool f;
	int IER = 0; // default value 

	std::ifstream in;

	in.open("constant.txt");

	double vec_size;
	in >> vec_size;
	std::vector<double> X;
	X.resize(vec_size);

	for (int i = 0; i < vec_size; i++) {
		in >> X[i];
	}

	std::vector<double> Y(vec_size);
	for (int i = 0; i < vec_size; i++) {
		in >> Y[i];
	}

	double XX;
	in >> XX;

	if (vec_size < 2) {
		IER = 1;
		std::cout << "A cubic spline cannot be constructed\n";
	}
	else if (vec_size >= 2) {
		for (int i = 1; i < vec_size; i++) {
			if (X[i - 1] > X[i]) IER = 2;
		}
		if (IER == 2) std::cout << "The ascending order of the argument in the input vector X is broken\n";
		else if (IER != 1 && IER != 2) {
			if (XX > X[vec_size - 1] || XX < X[0]) {
				std::cout << "The point doesnt belong to the segment: [" << X[0] << "; " << X[vec_size - 1] << "]\n";
				IER = 3;
			}
			else if (IER != 1 && IER != 2 && IER != 3 && IER == 0) {
				std::cout << "Set values: \n";
				for (int i = 0; i < vec_size; i++) {
					std::cout << X[i] << " ";
				}
				std::cout << "\n";
				for (int i = 0; i < vec_size; i++) {
					std::cout << Y[i] << " ";
				}
				std::cout << "\n";
				std::cout << "The point at which the cubic spline is calculated: " << XX << "\n";

				Spline s;
				s.set_boundary(Spline::first_deriv, 0.0, Spline::second_deriv, 0.0);
				s.set_points(X, Y);
				double result = s(XX);
				std::cout << "The result of the calculating the cubic spline at a point XX:=" << std::setprecision(10) << XX << " is " << result << "\n";
			}
		}
	}
}
void secondTest() {
	std::cout << "___________________________________________________________________________________________";
	std::cout << "\nSecond test: \n";
	bool f;
	int IER = 0; // default value 

	std::ifstream in;

	in.open("linear.txt");

	double vec_size;
	in >> vec_size;
	std::vector<double> X;
	X.resize(vec_size);

	for (int i = 0; i < vec_size; i++) {
		in >> X[i];
	}

	std::vector<double> Y(vec_size);
	for (int i = 0; i < vec_size; i++) {
		in >> Y[i];
	}

	double XX;
	in >> XX;

	if (vec_size < 2) {
		IER = 1;
		std::cout << "A cubic spline cannot be constructed\n";
	}
	else if (vec_size >= 2) {
		for (int i = 1; i < vec_size; i++) {
			if (X[i - 1] > X[i]) IER = 2;
		}
		if (IER == 2) std::cout << "The ascending order of the argument in the input vector X is broken\n";
		else if (IER != 1 && IER != 2) {
			if (XX > X[vec_size - 1] || XX < X[0]) {
				std::cout << "The point doesnt belong to the segment: [" << X[0] << "; " << X[vec_size - 1] << "]\n";
				IER = 3;
			}
			else if (IER != 1 && IER != 2 && IER != 3 && IER == 0) {
				std::cout << "Set values: \n";
				for (int i = 0; i < vec_size; i++) {
					std::cout << X[i] << " ";
				}
				std::cout << "\n";
				for (int i = 0; i < vec_size; i++) {
					std::cout << Y[i] << " ";
				}
				std::cout << "\n";
				std::cout << "The point at which the cubic spline is calculated: " << XX << "\n";

				Spline s;
				s.set_boundary(Spline::first_deriv, 1.0*X[0], Spline::second_deriv, 0.0);
				s.set_points(X, Y);
				double result = s(XX);
				std::cout << "The result of the calculating the cubic spline at a point XX:=" << XX << " is " << std::setprecision(2) << result << "\n";
			}
		}
	}
}
void thirdTest() {
	std::cout << "___________________________________________________________________________________________";
	std::cout << "\nThird test: \n";
	bool f;
	int IER = 0; // default value 

	std::ifstream in;

	in.open("quadratic.txt");

	double vec_size;
	in >> vec_size;
	std::vector<double> X;
	X.resize(vec_size);

	for (int i = 0; i < vec_size; i++) {
		in >> X[i];
	}

	std::vector<double> Y(vec_size);
	for (int i = 0; i < vec_size; i++) {
		in >> Y[i];
	}

	double XX;
	in >> XX;

	if (vec_size < 2) {
		IER = 1;
		std::cout << "A cubic spline cannot be constructed\n";
	}
	else if (vec_size >= 2) {
		for (int i = 1; i < vec_size; i++) {
			if (X[i - 1] > X[i]) IER = 2;
		}
		if (IER == 2) std::cout << "The ascending order of the argument in the input vector X is broken\n";
		else if (IER != 1 && IER != 2) {
			if (XX > X[vec_size - 1] || XX < X[0]) {
				std::cout << "The point doesnt belong to the segment: [" << X[0] << "; " << X[vec_size - 1] << "]\n";
				IER = 3;
			}
			else if (IER != 1 && IER != 2 && IER != 3 && IER == 0) {
				std::cout << "Set values: \n";
				for (int i = 0; i < vec_size; i++) {
					std::cout << X[i] << " ";
				}
				std::cout << "\n";
				for (int i = 0; i < vec_size; i++) {
					std::cout << Y[i] << " ";
				}
				std::cout << "\n";
				std::cout << "The point at which the cubic spline is calculated: " << XX << "\n";

				Spline s;
				s.set_boundary(Spline::first_deriv, 2.0*X[0], Spline::second_deriv, 2.0);
				s.set_points(X, Y);
				double result = s(XX);
				double *intPart = new double, fractPart;
				fractPart = modf(XX, intPart);
				if (fractPart == 0) {
					std::cout << "The result of the calculating the cubic spline at a point XX:=" << XX << " is " << std::setprecision(2) << result << "\n";
				}
				else {
					std::cout << "The result of the calculating the cubic spline at a point XX:=" << XX << " is " << std::setprecision(3) << result << "\n";
				}
			}
		}
	}
}
void fourthTest() {
	std::cout << "___________________________________________________________________________________________";
	std::cout << "\nFourth test: \n";
	bool f;
	int IER = 0; // default value 

	std::ifstream in;
	std::ifstream im;

	in.open("qubic2.txt");
	im.open("qubic.txt");

	double vec_size;
	in >> vec_size;
	std::vector<double> X;
	X.resize(vec_size);
	std::vector<double> Y(vec_size);

	for (int i = 0; i < vec_size; i++) {
		in >> X[i];
		in >> Y[i];
	}

	double size;
	im >> size;
	std::vector<double> X_;
	X_.resize(size);
	std::vector<double> Y_;
	Y_.resize(size);
	double buffer;


	for (int i = 0; i < size; i++) {
		im >> X_[i];
	}
	for (int i = 0; i < size; i++) {
		im >> Y_[i];
	}

	double XX;
	im >> XX;

	if (vec_size < 2) {
		IER = 1;
		std::cout << "A cubic spline cannot be constructed\n";
	}
	else if (vec_size >= 2) {
		for (int i = 1; i < size; i++) {
			if (X_[i - 1] > X_[i]) IER = 2;
		}
		if (IER == 2) std::cout << "The ascending order of the argument in the input vector X is broken\n";
		else if (IER != 1 && IER != 2) {
			if (XX > X_[size - 1] || XX < X_[0]) {
				std::cout << "The point doesnt belong to the segment: [" << X[0] << "; " << X[size - 1] << "]\n";
				IER = 3;
			}
			else if (IER != 1 && IER != 2 && IER != 3 && IER == 0) {
				std::cout << "Set values: \n";
				for (int i = 0; i < size; i++) {
					std::cout << X_[i] << " ";
				}
				std::cout << "\n";
				for (int i = 0; i < size; i++) {
					std::cout << Y_[i] << " ";
				}
				std::cout << "\n";
				std::cout << "The point at which the cubic spline is calculated: " << XX << "\n";

				Spline s;
				s.set_boundary(Spline::first_deriv, 3*X[0]*X[0], Spline::second_deriv, 6*X[vec_size - 1]);
				s.set_points(X, Y);
				double result = s(XX);
				std::cout << "The result of the calculating the cubic spline at a point XX:=" << std::setprecision(10) << XX << " is " << result << "\n";
			}
		}
	}
}
void fifthTest() {
	std::cout << "___________________________________________________________________________________________";
	std::cout << "\nFifth test: \n";
	bool f;
	int IER = 0; // default value 

	std::ifstream in;

	in.open("logarithm.txt");

	double vec_size;
	in >> vec_size;
	std::vector<double> X;
	X.resize(vec_size);

	for (int i = 0; i < vec_size; i++) {
		in >> X[i];
	}

	std::vector<double> Y(vec_size);
	for (int i = 0; i < vec_size; i++) {
		in >> Y[i];
	}

	double XX;
	in >> XX;

	if (vec_size < 2) {
		IER = 1;
		std::cout << "A cubic spline cannot be constructed\n";
	}
	else if (vec_size >= 2) {
		for (int i = 1; i < vec_size; i++) {
			if (X[i - 1] > X[i]) IER = 2;
		}
		if (IER == 2) std::cout << "The ascending order of the argument in the input vector X is broken\n";
		else if (IER != 1 && IER != 2) {
			if (XX > X[vec_size - 1] || XX < X[0]) {
				std::cout << "The point doesnt belong to the segment: [" << X[0] << "; " << X[vec_size - 1] << "]\n";
				IER = 3;
			}
			else if (IER != 1 && IER != 2 && IER != 3 && IER == 0) {
				std::cout << "Set values: \n";
				for (int i = 0; i < vec_size; i++) {
					std::cout << X[i] << " ";
				}
				std::cout << "\n";
				for (int i = 0; i < vec_size; i++) {
					std::cout << Y[i] << " ";
				}
				std::cout << "\n";
				std::cout << "The point at which the cubic spline is calculated: " << XX << "\n";

				Spline s;
				double first_bonundary = 1 / (X[0] * log(2));
				double second_boundary = -1 / (X[vec_size - 1] * X[vec_size - 1] * log(2));

				s.set_boundary(Spline::first_deriv, first_bonundary, Spline::second_deriv, second_boundary);
				s.set_points(X, Y);
				double result = s(XX);
				std::cout << "The result of the calculating the cubic spline at a point XX:=" << XX << " is " << result << "\n";
			}
		}
	}
}