#pragma once
namespace Foundation
{

	class LMString
	{
	public:
		typedef char* iterator;
		LMString(const char* str = "");
		LMString(LMString&& s);
		//拷贝构造函数（现代写法）
		LMString(const LMString& s);
		//析构函数
		~LMString();
	public:
		iterator begin();
		iterator end();
		//交换两个对象的数据
		void swap(LMString& s);
		//改变容量，大小不变
		void reserve(size_t n);
		//尾插字符
		void push_back(char ch);
		//返回C类型的字符串
		const char* c_str()const;
		LMString to_string(int value);


		//+=运算符重载
		LMString& operator+=(char ch);
		//赋值运算符重载（现代写法）
		LMString& operator=(const LMString& s);
		LMString& operator=(const LMString&& s);
		LMString& operator=(const char* s);
		//[]运算符重载
		char& operator[](size_t i);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}

