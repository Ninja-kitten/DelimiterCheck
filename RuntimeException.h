#ifndef _RUNTIME_EXCEPTION
#define _RUNTIME_EXCEPTION
#include <iostream>
#include <exception>
using namespace std;

class RuntimeException{
private:
string errorMsg;
public:
RuntimeException(const string& err){errorMsg = err; }
string getMessage() const { return errorMsg; }
};

class StackEmpty : public RuntimeException
{
	public:
	StackEmpty(const string& err) : RuntimeException(err){}
};


class StackFull : public RuntimeException
{
	public:
	StackFull(const string& err) : RuntimeException(err){}
};

class FileNotFound : public RuntimeException
{
	public:
	FileNotFound(const string& err) : RuntimeException(err){}
};

class UnmatchedDelimiter : public RuntimeException
{
	public:
	UnmatchedDelimiter(const string& err) : RuntimeException(err){}
};
#endif
