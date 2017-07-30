#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

//Calculated in Main
VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
	const vector<VectorXd> &ground_truth) {
	/**
	TODO:
	* Calculate the RMSE here.
	*/

	VectorXd rmse(4);
	rmse << 0,0,0,0;

	if(estimations.size() != ground_truth.size() || estimations.size()==0){
		cout << "Invalid estimation or ground_truth data" << endl;
		return rmse;
	}

	//Accumulate square residuals
	for(unsigned int i=0; i < estimations.size(); i++){
		VectorXd residual = estimations[i] - ground_truth[i];

		residual = residual.array()*residual.array();
		rmse += residual;
	}

	//Calculate the mean 
	rmse = rmse/estimations.size();

//Calculate the square root
	rmse = rmse.array().sqrt();

	return rmse;

	//VectorXd temp(4);
	//temp << 1, 2, 3, 4;
	//return temp;
}

MatrixXd Tools::CalculateJacobian(const VectorXd& x_state) {
	/**
	TODO:
	* Calculate a Jacobian here.
	*/
	MatrixXd Hj(3, 4);
	//recover state parameters
	float px = x_state(0);
	float py = x_state(1);
	float vx = x_state(2);
	float vy = x_state(3);

	 if (fabs(px) < 0.0001 and fabs(py) < 0.0001){
	  px = 0.0001;
	  py = 0.0001;
  }
	//pre-compute a set of terms to avoid repeated calculations
	float c1 = px*px + py*py;
	if(fabs(c1) < 0.0000001){
	c1 = 0.0000001;
  }

	float c2 = sqrt(c1);
	float c3 = (c1*c2);

	//Check division by zero
	if(fabs(c1) < 0.0001){
		cout << "CalculateJacobian () - Error - Divison by Zero" << endl;
		return Hj;
	}
	//Jacobian
	Hj << (px/c2), (py/c2), 0, 0,
		  -(py/c1), (px/c1), 0, 0,
		  py*(vx*py - vy*px)/c3, px*(px*vy - py*vx)/c3, px/c2, py/c2;
	
	cout<<"The Jacobian matrix is: "<<Hj<<endl;

	return Hj;

	//MatrixXd temp(2,2);
	//return temp;
}
