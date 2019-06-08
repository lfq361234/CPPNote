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
	Dog(){
		cout <<"Nameless dog is created"<<endl;
		_name="nameless";
	}
	~Dog(){
		cout << "Dog is destroyed: "<< _name<<endl;
	}
	void bark(){
		cout << "Dog " << _name << " barks"<<endl;
	}
};

void foo(){
	shared_ptr<Dog> p1=make_shared<Dog>("Gun"); //using default deleter: operator delete
	shared_ptr<Dog> p2=shared_ptr<Dog>(new Dog("Tank"),[](Dog* p){
		cout<< "Custom deleting: ";
		delete p;
	});// customized deleter

	//Why should we use coustomized deleter? Consider following comment operation 
	//shared_ptr<Dog> p3(new Dog[3]); 
	//Dog[1] and Dog[2] have memory leak
	//How should we do?
	
	shared_ptr<Dog> p4(new Dog[3],[](Dog*p){
		delete[] p;
	});// All 3 dogs will be deleted when p4 goes out of scope

	
	Dog* d=p1.get();//returns the raw pointer,and it should be used very carefully	
	//Case1:
	//delete d;
	//this will delete Dog("Gun") twice after getting out of scope
	//Case2:
	//shared_ptr<Dog> p2(d);
	//when going out of scope, Dog("Gun") will be deleted twice

}
int main(){
	foo();
	system("pause");
	return 0;
}
