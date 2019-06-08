#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> outcome;
	stringstream ss(str); // Turn the string into a stream.
  	string substr;  //split part
 	while(getline(ss, substr, delimiter)) {
    		outcome.push_back(substr);
  	}
 	return outcome;
}

int main(){
	string A="abc,def,ccd";
	vector<string> vec=split(A,',');
	vector<string>::iterator itr=vec.begin();
	for(itr=vec.begin();itr!=vec.end();itr++){
		cout << *itr << endl;
	}
	system("pause");
	return 0;
}
