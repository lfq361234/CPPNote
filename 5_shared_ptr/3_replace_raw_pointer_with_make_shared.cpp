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
	shared_ptr<Dog> p(new Dog("Gun")); //Count==1 p.use_count()==1 (calculate how many shared_ptr point to this memory address)
	{
		shared_ptr<Dog> p2=p; //Count==2 p.use_count()==2, p2.use_count()==2 
		p2->bark();
		cout<< p.use_count()<<endl; //2
	}
	//count==1  (when get out of scope, p2 is no longer accessible, so the number of shared_ptr reduce to one)
	p->bark();
}//count==0  (when the count of the shared_ptr=0, free the memory of Dog("Gun") automatically)
int main(){
	foo();
	
	
	//An object should be assigned to a smart pointer as soon as it is created. Raw pointer should not be used
	Dog* d =new Dog("Tank");//bad idea
	shared_ptr<Dog> p=make_shared<Dog>("Tank");//faster and saver
        (*p).bark();	
		system("pause");
	return 0;
}
