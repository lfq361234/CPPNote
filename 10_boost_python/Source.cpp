#include<boost/python.hpp>
#include <iostream>
#include<stdio.h>
using namespace std;

using namespace boost::python;
//#define BOOST_PYTHON_STATIC_LIB

char const* greet()
{
	return "hello, world";
}

BOOST_PYTHON_MODULE(boostpy03)			// Python model start
{
	using namespace boost::python;		//open namespace
	def ("greet", greet);
}
