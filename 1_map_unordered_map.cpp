#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<iterator>
#include<algorithm>
#include<numeric>
#include<functional>



int main(){
	cout << "create map: mymap(always sorted)(implemented by binary tree) "<< endl;
	map<char,int> mymap;
	//insert practice
	mymap.insert(pair<char,int>('a',100));
	mymap.insert(make_pair('z',200));
	mymap.insert(make_pair('c',300));
	//show content
	map<char,int>::iterator itr;
	for(itr=mymap.begin();itr!=mymap.end();itr++){
		cout << itr->first <<" => " << itr->second <<endl; // same as cout << (*itr).first <<" => " << (*itr).second <<endl; 
	}
	//find practice
	itr=mymap.find('z');
	cout << "find z : "<<endl;
	cout << itr->first <<" => " << itr->second <<endl;
	
	//insert through iterator
	mymap.insert(itr,make_pair('b',400));
	cout << "insert (b,400) to mymap through iterator: "<<endl;
	for(itr=mymap.begin();itr!=mymap.end();itr++){
		cout << itr->first <<" => " << itr->second <<endl;
	}
	//erase through iterator
	itr=mymap.find('c');
	if(itr!=mymap.end()){//Be Careful: if iterator does not find content, this will return the end iterator
		mymap.erase(itr);
	}
	cout << "erase 'c' through iterator:"<<endl;
	for(itr=mymap.begin();itr!=mymap.end();itr++){
		cout << itr->first <<" => " << itr->second <<endl;
	}
	//erase data immediately
	int iferase = mymap.erase('b');
	cout <<"erase 'b' immediately: "<<endl;	
	cout << "iferase: "<< iferase <<endl;
	for(itr=mymap.begin();itr!=mymap.end();itr++){
		cout << itr->first <<" => " << itr->second <<endl;
	}
	//get the size of map
	cout << "size of mymap: "<<endl;
	cout << mymap.size()<< endl;
	//no duplicate key
	pair<map<char,int>::iterator,bool> ret;
	ret=mymap.insert(make_pair('a',1000));
	cout << "insert('a',1000) to mymap(no duplicated key):  " << endl;
	cout << "position of iterator of insertion: "<< endl; 
	cout << ret.first->first << endl;
	cout << "is insertion sucessful: "<<endl;
	cout << ret.second << endl;
	cout << "show mymap after insertion (no duplicated key)"<<endl;
	for(itr=mymap.begin();itr!=mymap.end();itr++){
		cout << itr->first <<" => " << itr->second <<endl;
	}
	//keys can not be modified, they are read-only
	//(*ret.first).first='m'; assinment of read-only member error
	//values can be modified
	cout << "change value of 'a' to 1000"	<< endl;
	(*ret.first).second=1000; 
	for(itr=mymap.begin();itr!=mymap.end();itr++){
		cout << itr->first <<" => " << itr->second <<endl;
	}
	

	cout<<"============================================================================================================="<<endl;
	
	
	cout << "create unordered map: u_map(implemented by hash table) (order is messy)"<< endl;
	unordered_map<char,int> u_map;
	//insert practice
	u_map.insert(pair<char,int>('a',100));
	u_map.insert(make_pair('z',200));
	u_map.insert(make_pair('c',300));
	u_map.insert(make_pair('x',300));
	u_map.insert(make_pair('d',400));
	//show content(order is random and messy)
	unordered_map<char,int>::iterator uitr;
	for(uitr=u_map.begin();uitr!=u_map.end();uitr++){
		cout << uitr->first <<" => " << uitr->second <<endl; // same as cout << (*itr).first <<" => " << (*itr).second <<endl; 
	}
	//find practice
	uitr=u_map.find('a');
	cout << "find a : "<<endl;
	cout << uitr->first <<" => " << uitr->second <<endl;	
	//insert through iterator
	u_map.insert(uitr,make_pair('b',400));
	cout << "insert (b,400) to u_map through iterator: "<<endl;
	for(uitr=u_map.begin();uitr!=u_map.end();uitr++){
		cout << uitr->first <<" => " << uitr->second <<endl;
	}
	//erase through iterator
	uitr=u_map.find('c');
	if(uitr!=u_map.end()){//Be Careful: if iterator does not find content, this will return the end iterator
		u_map.erase(uitr);
	}
	cout << "erase 'c' through iterator:"<<endl;
	for(uitr=u_map.begin();uitr!=u_map.end();uitr++){
		cout << uitr->first <<" => " << uitr->second <<endl;
	}
	//erase data immediately
	int ifuerase = u_map.erase('b');
	cout <<"erase 'b' immediately: "<<endl;	
	cout << "ifuerase: "<< ifuerase <<endl;
	for(uitr=u_map.begin();uitr!=u_map.end();uitr++){
		cout << uitr->first <<" => " << uitr->second <<endl;
	}
	//get the size of unordered map
	cout << "size of u_map: "<<endl;
	cout << u_map.size()<< endl;
	//no duplicate key
	pair<unordered_map<char,int>::iterator,bool> ret2;
	ret2=u_map.insert(make_pair('a',1000));
	cout << "insert('a',1000) to u_map(no duplicated key):  " << endl;
	cout << "position of iterator of insertion: "<< endl; 
	cout << ret2.first->first << endl;
	cout << "is insertion sucessful: "<<endl;
	cout << ret2.second << endl;
	cout << "show u_map after insertion (no duplicated key)"<<endl;
	for(uitr=u_map.begin();uitr!=u_map.end();uitr++){
		cout << uitr->first <<" => " << uitr->second <<endl;
	}
	//keys can not be modified, they are read-only
	//(*ret2.first).first='m'; assinment of read-only member error
	//values can be modified
	cout << "change value of 'a' to 1000"	<< endl;
	(*ret2.first).second=1000; 
	for(uitr=u_map.begin();uitr!=u_map.end();uitr++){
		cout << uitr->first <<" => " << uitr->second <<endl;
	}
	//hash table APIs:
	cout << "load factor(no. of elements/ no. of buckets): " << endl;
	cout << u_map.load_factor()<<endl;
	cout << "bucket count: "<<endl;		
	cout << u_map.bucket_count()<<endl;
	cout << "bucket position of a: "<<endl;
	cout << u_map.bucket('a')<<endl;
	system("pause");
	return 0;
}
