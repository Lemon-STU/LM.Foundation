#pragma once
namespace Foundation
{

	class LMString
	{
	public:
		typedef char* iterator;
		LMString(const char* str = "");
		LMString(LMString&& s);
		//�������캯�����ִ�д����
		LMString(const LMString& s);
		//��������
		~LMString();
	public:
		iterator begin();
		iterator end();
		//�����������������
		void swap(LMString& s);
		//�ı���������С����
		void reserve(size_t n);
		//β���ַ�
		void push_back(char ch);
		//����C���͵��ַ���
		const char* c_str()const;
		LMString to_string(int value);


		//+=���������
		LMString& operator+=(char ch);
		//��ֵ��������أ��ִ�д����
		LMString& operator=(const LMString& s);
		LMString& operator=(const LMString&& s);
		LMString& operator=(const char* s);
		//[]���������
		char& operator[](size_t i);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}

