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
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(5);
	vec.push_back(3);
	cout << "vec.empty(): "<<endl;
	cout << vec.empty() << endl;
	cout << "vec.capacity(): "<<endl;
	cout << vec.capacity() <<endl;
	cout << "vec.size():"<<endl;
	cout << vec.size() <<endl;
	//when push_back elements exceed capacity, vector will allocate new memory space with bigger size and copy the data
	//from old array to new memory space. After that, vector will push_back element in new array and delete memory space of old array
	//copy constructor
	vector<int> vec2(vec);
	cout << "vec2.size():"<<endl;
	cout << vec2.size() <<endl;
	//clear
	vec.clear();
	cout << "vec.size() after clear: "<<endl;
	cout << vec.size() <<endl;
	//swap
	vec.swap(vec2);
	cout << "vec.size() after swap with vec2: "<<endl;
	cout << vec.size() <<endl;
	//iterator application
	//print out elements
	vector<int>::iterator itr=vec.begin();
	cout << "elements in vec:" << endl; 
	for(itr=vec.begin();itr!=vec.end();itr++){
		cout << *itr <<" ";
	}
	cout <<endl;
	//find
	itr=find(vec.begin(),vec.end(),5);
	cout << "find 5 in vec:"<<endl;
	cout << *itr <<endl;	
	//insert (before the position iterator point to)  
	vec.insert(itr,10);
	cout <<"elements in vec after insert 10 with iterator point to 5:"<<endl;
	for(int i=0;i<vec.size();i++){
		cout << vec[i]<<" ";
	}
	cout << endl;
	//erase
	itr=find(vec.begin(),vec.end(),5);
	vec.erase(itr);
	cout <<"elements in vec after erase iterator point to 5:"<<endl;
	for(itr=vec.begin();itr!=vec.end();itr++){
		cout << *itr <<" ";
	}
	cout << endl;
	//time complexity note:
	//insert/remove at beginning and middle position ==> O(n)
	//insert/remove at end position ==> O(1)
	//search ==> O(n)
	
	//insert iterator
	vector<int> vec3={3,4};
	vector<int> vec4={1,2,10,13};
	vector<int>::iterator it=find(vec4.begin(),vec4.end(),10);
	insert_iterator<vector<int>> i_itr=inserter(vec4,it);
	copy(vec3.begin(),vec3.end(), //source
			i_itr);       //destination
	cout <<"insert vec3 into vec4:" <<endl;
	for(it=vec4.begin();it!=vec4.end();it++){
		cout << *it <<" ";
	}
	cout << endl;
	//reverse
	reverse_iterator<vector<int>::iterator> ritr;
	cout <<"reverse vec4:"<<endl;
	for(ritr=vec4.rbegin();ritr!=vec4.rend();ritr++){
		cout << *ritr <<" ";
	}
	cout << endl;


	//algorithm   [begin,end) operation
	vector<int> v={100,55,32,2,4,89,45,67};
	//minimum	
	itr=min_element(v.begin(),v.end());
	cout << "min of v: "<<endl;
	cout << *itr <<endl;
	//sort
	sort(v.begin(),itr);
	cout <<"partial sort :"<<endl;//sort before min=2(2 is not included)
	for(itr=v.begin();itr!=v.end();itr++){
		cout << *itr <<" ";
	}
	cout << endl;
	//reverse
	itr=min_element(v.begin(),v.end());
	cout << "partial reverse : "<<endl;
	reverse(itr,v.end());//reverse after min=2 (2 is included)
	for(itr=v.begin();itr!=v.end();itr++){
		cout << *itr <<" ";
	}
	cout << endl;
	//insert from the end
	itr=v.begin()+2;
	vector<int> vec5={9};
	vec5.insert(vec5.end(),itr,v.end());
	cout << "insert v into vec5:" <<endl;
	for(itr=vec5.begin();itr!=vec5.end();itr++){
		cout << *itr <<" ";
	}
	cout << endl;
	system("pause");

	return 0;
}
