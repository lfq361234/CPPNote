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
	shared_ptr<Dog> p1=make_shared<Dog>("Gun");
	//for the count of shared pointer
	//shared_ptr<Dog> p2=make_shared<Dog>("Gun"); p2.use_count()==1
	//shared_ptr<Dog> p2=p1;                      p2.use_count()==2
	

	
		
	shared_ptr<Dog> p2=make_shared<Dog>("Tank");
	//Gun is deleted after any of the following three opeerations
	p1=p2;
	p1=nullptr;
	p1.reset();

}//Tank is deleted after getting out of the scope
int main(){
	foo();
	//p3 and p4 point to different memory address of Dog("Tank") 
	shared_ptr<Dog> p3=make_shared<Dog>("Tank");
	shared_ptr<Dog> p4=make_shared<Dog>("Tank");
	system("pause");
	return 0;
}
