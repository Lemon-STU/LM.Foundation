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
	//�������캯�����ִ�д����
	String(const String& s);
	//��������
	~String();
public:
	iterator begin();
	iterator end();
	//�����������������
	void swap(String& s);
	//�ı���������С����
	void reserve(size_t n);
	//β���ַ�
	void push_back(char ch);
	//����C���͵��ַ���
	const char* c_str()const;
	String to_string(int value);


	//+=���������
	String& operator+=(char ch);
	//��ֵ��������أ��ִ�д����
	String& operator=(const String& s);
	String& operator=(const String&& s);
	String& operator=(const char* s);
	//[]���������
	char& operator[](size_t i);
private:
	char* _str;
	size_t _size;
	size_t _capacity;
};
std::ostream& operator<<(std::ostream& os,const Foundation::String& str);
std::ostream& operator<<(std::ostream& os, const Foundation::String&& str);

