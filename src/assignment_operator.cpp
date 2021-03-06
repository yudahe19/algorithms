/*
* Copyright(c) 2019 Jiau Zhang
* For more information see <https://github.com/JiauZhang/algorithms>
* 
* This repo is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation
*
* It is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with THIS repo. If not, see <http://www.gnu.org/licenses/>.
*/

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

class CMyString
{
public:
	CMyString(char* pData=NULL);
	CMyString(const CMyString& str);
	CMyString& operator=(const CMyString& str);
	~CMyString();
	Print();
private:
	char* m_pData;	
};

CMyString::CMyString(char* pData)
{
	if(pData==NULL) {
		m_pData = new char[1];
		m_pData[0] = '\0';
	} else {
		int length = strlen(pData);
		m_pData = new char[length+1];
		strcpy(m_pData, pData);
	}
}

CMyString::~CMyString()
{
    delete[] m_pData;
}

CMyString::CMyString(const CMyString& str)
{
	if(this != &str) {
		int length = strlen(str.m_pData);
		m_pData = new char[length+1];
		strcpy(m_pData, str.m_pData);
	}
}

CMyString::Print()
{
	if(m_pData==NULL)
		cout << "no data" << endl;
	else {
		char* temp = m_pData;
		while(*temp!='\0') {
			cout << *temp;
			temp++;
		}
		cout << endl;
	}		
}

CMyString& CMyString::operator=(const CMyString& str)
{
	if(this != &str) {
		CMyString strTemp(str);
		char* p_Temp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = p_Temp;
	}
	
	return *this;
}

int main(int argc, char** argv)
{
	char* pData = "assignment opreator";
	CMyString strTest1(pData);
	cout << "test1" << endl;
	strTest1.Print();
	CMyString strTest2(strTest1);
	cout << "test2" << endl;
	strTest2.Print();
	CMyString strTest3, strTest4;
	cout << "test3" << endl;
	strTest3=strTest4=strTest1;
	strTest3.Print();
	strTest4.Print();
	cout << "test4" << endl;
	strTest4 = strTest4;
	strTest4.Print();		
	
	return 0;
}
