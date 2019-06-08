#include <cstdlib>
#include <fstream>
#include <ios>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include<vector>


using namespace std;

// matrix manipulation
#include"matrix.h"
	// examples for using CMatrix    
	/*CMatrix a("A", 5, 5);
	a.m_pData[0][0]=5.9;
	a.m_pData[1][0]=5.6;
	CMatrix ainv = a.Inverse();
	CMatrix atran = a.Transpose();
	CMatrix b=a*a;
	cout << a.m_pData[0][0]<<endl;*/

int main(){
	//read data from csv file to put in x1,x2,x3,x4,y
	vector<double> x1,x2,x3,x4,y;
	fstream file;
	file.open("regression_input.txt",ios::in);

	string line;

	
	for(int j=0;j<5;j++){
		getline( file, line);                //readfile until '\n'
		istringstream templine(line);            //convert string to stream
		string data;
		int i = 0;
		while (getline( templine, data,'\t')){	//read file until ','
			if(j==0){
				x1.push_back(atof(data.c_str()));  //convert string to number
			}
			if(j==1){
				x2.push_back(atof(data.c_str()));  //convert string to number
			}
			if(j==2){
				x3.push_back(atof(data.c_str()));  //convert string to number
			}
			if(j==3){
				x4.push_back(atof(data.c_str()));  //convert string to number
			}
			if(j==4){
				y.push_back(atof(data.c_str()));  //convert string to number
			}
		}
	}

	file.close();
	if (y.size() == 201 && x1.size() == 201 && x2.size() == 201 && x3.size() == 201 && x4.size() == 201) {
		//put data in martix Y and matrix X
		CMatrix Y("Y", 200, 1);
		CMatrix X("X", 200, 5);
		for (int i = 0; i < 200; i++) {
			Y.m_pData[i][0] = y[i + 1];
			X.m_pData[i][0] = 1;
			X.m_pData[i][1] = x1[i + 1];
			X.m_pData[i][2] = x2[i + 1];
			X.m_pData[i][3] = x3[i + 1];
			X.m_pData[i][4] = x4[i + 1];
		}
		//calculate coefficients by matrix Beta_hat=((X'X)^-1)X'Y
		CMatrix XT = X.Transpose();
		CMatrix a = XT * X;
		CMatrix b = a.Inverse();
		CMatrix c = b * XT;
		CMatrix Beta_hat = c * Y;
		cout << "Coefficient of x1(b1):" << endl;
		cout << Beta_hat.m_pData[1][0] << endl;
		cout << "Coefficient of x2(b2):" << endl;
		cout << Beta_hat.m_pData[2][0] << endl;
		cout << "Coefficient of x3(b3):" << endl;
		cout << Beta_hat.m_pData[3][0] << endl;
		cout << "Coefficient of x4(b4):" << endl;
		cout << Beta_hat.m_pData[4][0] << endl;
	 }
	else {
		cout << "data input is wrong" << endl;
	}
	
	
	
	

	system("pause");
	return 0;
}
