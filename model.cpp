/*
 * model.cpp
 *
 *  Created on: Aug 8, 2021
 *      Author: ahmed
 */


#include <iostream>
#include <cmath>

using namespace std;

float beta = 0;
float thetaDot = 0;
float theta = 0;
float length = 0.5;
float I = 1;
float sampleTime = 0.5;
float input[3]={5,5,3.14/30};
float output[3];
float X_dot = 0;
float Y_dot = 0;


void model(void)
{
	for (int i =0 ; i<201 ; i++)
	{

		beta=atan(   (  length*(tan(input[2])/I)  )  );
		X_dot=input[0]*cos(theta+beta);
		Y_dot=input[0]*sin(theta+beta);
		thetaDot=input[0]*cos(beta)*tan(input[2])/I;
		output[0]+=X_dot*sampleTime;
		output[1]+=Y_dot*sampleTime;
		theta+=thetaDot*sampleTime;
		output[2]=theta;
	    output[2]=remainder(theta,2*3.14);
		cout<<"(x = "<<output[0]<<"\t"<< ", y = " <<output[1]<<"\t"<< ", theta= "<<output[2]<<")"<<endl;
	}
}

int main(void)
{
	model();

}

