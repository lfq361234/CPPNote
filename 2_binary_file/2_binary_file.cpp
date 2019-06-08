#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;

int main(){
	double n=34335.67445;	
	//write a double number into file
	fstream file;
	file.open("binaryfile.bin", ios::out|ios::binary);
	file.write((char*)&n,sizeof(n));
	file.close();
	//read  a double numberfrom the file 
	double r;
	fstream finC;
	finC.open("binaryfile.bin",ios::in|ios::binary);
	finC.read((char*)&r,sizeof(r));
	finC.close();	
	cout <<setprecision(10)<<r << endl;
	system("pause");
	return 0;
}
