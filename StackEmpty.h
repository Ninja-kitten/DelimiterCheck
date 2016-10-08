#include <iostream>
#include <exception>
using namespace std;

struct StackEmpty : public exception
{
	public:
	StackEmpty(const string& err) : RuntimeException(err)
};


struct StackFull : public exception
{
	public:
	StackEmpty(const string& err) : RuntimeExceptionERR
};
