#include<iostream>
#include<string>
#include<memory> //for shared_ptr
using namespace std;
class Dog{
	string _name;
public:
	Dog(string name){
		cout << "Dog is created: "<< name <<endl;
		_name=name;
	}
	~Dog(){
		cout << "Dog is destroyed: "<< _name<<endl;
	}
	void bark(){
		cout << "Dog " << _name << " barks"<<endl;
	}
};

void foo(){
	Dog* p=new Dog("Gun");
	// ...
	// delete p;
	// ...
	p->bark();// If you delete p first, p will be a dangling pointer - undefined behavior
}//If you do not delete p, it will cause memory leak  ( Now it is memory leak version)
//shared_ptr can help us to prevent dangling pointer and memory leak problem

int main(){
	system("pause");
	return 0;
}
