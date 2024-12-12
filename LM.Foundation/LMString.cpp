#include "pch.h"
#include "LMString.h"
#include <iostream>
using namespace Foundation;

String::iterator String::begin()
{
	return _str; //�����ַ����е�һ���ַ��ĵ�ַ
}

String::iterator String::end()
{
	return _str + _size; //�����ַ��������һ���ַ��ĺ�һ���ַ��ĵ�ַ
}

String::String(const char* str)
{
	_size = std::strlen(str); //��ʼʱ���ַ�����С����Ϊ�ַ�������
	_capacity = _size; //��ʼʱ���ַ�����������Ϊ�ַ�������
	_str = new char[_capacity + 1]; //Ϊ�洢�ַ������ٿռ䣨�࿪һ�����ڴ��'\0'��
	strcpy_s(_str, _capacity + 1, str); //��C�ַ����������ѿ��õĿռ�
}

void String::swap(String& s)
{
	//���ÿ����swap
	std::swap(_str, s._str); //�������������C�ַ���
	std::swap(_size, s._size); //������������Ĵ�С
	std::swap(_capacity, s._capacity); //�����������������
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
	String tmp(s._str); //���ù��캯���������һ��C�ַ���Ϊs._str�Ķ���
	swap(tmp); //��������������
}

String& String::operator=(const String& s)
{
	String tmp(s); //��s�������������tmp
	swap(tmp); //��������������
	return *this; //������ֵ��֧��������ֵ��
}

String& String::operator=(const String&& s)
{
	String tmp(s); //��s�������������tmp
	swap(tmp); //��������������
	return *this; //������ֵ��֧��������ֵ��
}

String& Foundation::String::operator=(const char* s)
{
	String tmp(s); //��s�������������tmp
	swap(tmp); //��������������
	return *this; //������ֵ��֧��������ֵ��
}

String::~String()
{
	if (_str)
	{
		delete[] _str;  //�ͷ�_strָ��Ŀռ�
		_str = nullptr; //��ʱ�ÿգ���ֹ�Ƿ�����
	}
	_size = 0;      //��С��0
	_capacity = 0;  //������0
}

char& String::operator[](size_t i)
{
	//assert(i < _size); //����±�ĺϷ���
	return _str[i]; //���ض�Ӧ�ַ�
}

void String::reserve(size_t n)
{
	if (n > _capacity) //��n���ڶ���ǰ����ʱ����ִ�в���
	{
		char* tmp = new char[n + 1]; //�࿪һ���ռ����ڴ��'\0'
		strncpy_s(tmp, _size + 1, _str, _size + 1); //������ԭ����C�ַ�����������������'\0'��
		delete[] _str; //�ͷŶ���ԭ���Ŀռ�
		_str = tmp; //���¿��ٵĿռ佻��_str
		_capacity = n; //�������Ÿı�
	}
}

void String::push_back(char ch)
{
	if (_size == _capacity) //�ж��Ƿ���Ҫ����
	{
		reserve(_capacity == 0 ? 4 : _capacity * 2); //����������Ϊԭ��������
	}
	_str[_size] = ch; //���ַ�β�嵽�ַ���
	_str[_size + 1] = '\0'; //�ַ����������'\0'
	_size++; //�ַ����Ĵ�С��һ
}

String& String::operator+=(char ch)
{
	push_back(ch); //β���ַ���
	return *this; //������ֵ��֧������+=��
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

