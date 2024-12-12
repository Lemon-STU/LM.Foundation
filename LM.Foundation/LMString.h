#pragma once
#include <iostream>
namespace Foundation
{
	class String;
}
class  Foundation::String
{
public:
	typedef char* iterator;
	String(const char* str = "");
	String(String&& s);
	//拷贝构造函数（现代写法）
	String(const String& s);
	//析构函数
	~String();
public:
	iterator begin();
	iterator end();
	//交换两个对象的数据
	void swap(String& s);
	//改变容量，大小不变
	void reserve(size_t n);
	//尾插字符
	void push_back(char ch);
	//返回C类型的字符串
	const char* c_str()const;
	String to_string(int value);


	//+=运算符重载
	String& operator+=(char ch);
	//赋值运算符重载（现代写法）
	String& operator=(const String& s);
	String& operator=(const String&& s);
	String& operator=(const char* s);
	//[]运算符重载
	char& operator[](size_t i);
private:
	char* _str;
	size_t _size;
	size_t _capacity;
};
std::ostream& operator<<(std::ostream& os,const Foundation::String& str);
std::ostream& operator<<(std::ostream& os, const Foundation::String&& str);

