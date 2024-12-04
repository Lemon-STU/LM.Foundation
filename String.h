#pragma once
#include "Encoding.h"
namespace Foundation
{
	class String
	{
	public:
        String(char* value);
        String(char c, int count);
        String(char* value, int startIndex, int length);
        String(char* value, int startIndex, int length);
        String(char* value, int startIndex, int length, Encoding enc);
	public:
		static const String Empty;
		static String Join(String separator,String value[]);
		static String Concat(String values[]);
		
	public:
		bool Equals(String value);
		void Append(String value);
		void Split(String separator);
		void IndexOf(String value);
		template<typename T>
		String Format(String format,T arg0);
		bool EndsWith(char value);
		bool StartsWith(String value);
		String ToLower();
		String ToUpper();
		String Trim();
	private:
		int  m_stringLength;
		char m_firstChar;
		const int TrimHead = 0;
		const int TrimTail = 1;
		const int TrimBoth = 2;
	};
}


