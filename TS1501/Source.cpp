//Name: 劉家成
//Date: 2023/06/06
//Last Update: 2023/06/06
//Problem statement: 用set來存取name.txt的資料，並且輸出

#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int main()
{
	ifstream in("name.txt"); //開啟檔案
	set<string> myset; //宣告set
	string name; //宣告name
	while (getline(in, name)) //讀取檔案
	{
		myset.insert(name); //將name存入set
	}
	for (auto s = myset.begin(); s != myset.end(); s++) 
	{
		cout << *s << endl; //輸出set
	}
}