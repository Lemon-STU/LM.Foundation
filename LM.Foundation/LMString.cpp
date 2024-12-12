#include "pch.h"
#include "LMString.h"
#include <iostream>
using namespace Foundation;

String::iterator String::begin()
{
	return _str; //返回字符串中第一个字符的地址
}

String::iterator String::end()
{
	return _str + _size; //返回字符串中最后一个字符的后一个字符的地址
}

String::String(const char* str)
{
	_size = std::strlen(str); //初始时，字符串大小设置为字符串长度
	_capacity = _size; //初始时，字符串容量设置为字符串长度
	_str = new char[_capacity + 1]; //为存储字符串开辟空间（多开一个用于存放'\0'）
	strcpy_s(_str, _capacity + 1, str); //将C字符串拷贝到已开好的空间
}

void String::swap(String& s)
{
	//调用库里的swap
	std::swap(_str, s._str); //交换两个对象的C字符串
	std::swap(_size, s._size); //交换两个对象的大小
	std::swap(_capacity, s._capacity); //交换两个对象的容量
}

String::String(String&& s)
	:_str(nullptr)
	, _size(0)
	, _capacity(0)
{
	swap(s);
}

String::String(const String& s)
	:_str(nullptr)
	, _size(0)
	, _capacity(0)
{
	String tmp(s._str); //调用构造函数，构造出一个C字符串为s._str的对象
	swap(tmp); //交换这两个对象
}

String& String::operator=(const String& s)
{
	String tmp(s); //用s拷贝构造出对象tmp
	swap(tmp); //交换这两个对象
	return *this; //返回左值（支持连续赋值）
}

String& String::operator=(const String&& s)
{
	String tmp(s); //用s拷贝构造出对象tmp
	swap(tmp); //交换这两个对象
	return *this; //返回左值（支持连续赋值）
}

String& Foundation::String::operator=(const char* s)
{
	String tmp(s); //用s拷贝构造出对象tmp
	swap(tmp); //交换这两个对象
	return *this; //返回左值（支持连续赋值）
}

String::~String()
{
	if (_str)
	{
		delete[] _str;  //释放_str指向的空间
		_str = nullptr; //及时置空，防止非法访问
	}
	_size = 0;      //大小置0
	_capacity = 0;  //容量置0
}

char& String::operator[](size_t i)
{
	//assert(i < _size); //检测下标的合法性
	return _str[i]; //返回对应字符
}

void String::reserve(size_t n)
{
	if (n > _capacity) //当n大于对象当前容量时才需执行操作
	{
		char* tmp = new char[n + 1]; //多开一个空间用于存放'\0'
		strncpy_s(tmp, _size + 1, _str, _size + 1); //将对象原本的C字符串拷贝过来（包括'\0'）
		delete[] _str; //释放对象原本的空间
		_str = tmp; //将新开辟的空间交给_str
		_capacity = n; //容量跟着改变
	}
}

void String::push_back(char ch)
{
	if (_size == _capacity) //判断是否需要增容
	{
		reserve(_capacity == 0 ? 4 : _capacity * 2); //将容量扩大为原来的两倍
	}
	_str[_size] = ch; //将字符尾插到字符串
	_str[_size + 1] = '\0'; //字符串后面放上'\0'
	_size++; //字符串的大小加一
}

String& String::operator+=(char ch)
{
	push_back(ch); //尾插字符串
	return *this; //返回左值（支持连续+=）
}

const char* String::c_str() const
{
	return _str;
}

String String::to_string(int value)
{
	bool flag = true;
	if (value < 0)
	{
		flag = false;
		value = 0 - value;
	}
	String str;
	while (value > 0)
	{
		int x = value % 10;
		value /= 10;
		str += (x + '0');
	}
	if (flag == false)
	{
		str += '-';
	}
	std::reverse(str.begin(), str.end());
	return str;
}

std::ostream& operator<<(std::ostream& os,const String& str)
{
	os << str.c_str();
	return os;
}
std::ostream& operator<<(std::ostream& os, const String&& str)
{
	os << str.c_str();
	return os;
}

