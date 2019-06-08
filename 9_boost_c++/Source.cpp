#include <iostream>
using namespace std;
#include<iterator>
#include<algorithm>
#include <boost/lexical_cast.hpp>
#include<boost/foreach.hpp>
using boost::lexical_cast;
using boost::bad_lexical_cast;

int main()
{
	int s = 23;
	string str = lexical_cast<string>(s);
	str = "Message: " + lexical_cast<string>('A') + " " + lexical_cast<string>(34.5);
	cout << str << endl;
	system("pause");
	return 0;
}