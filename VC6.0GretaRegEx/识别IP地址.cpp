/* quoto0: http://www.cnblogs.com/giszhang/archive/2009/05/22/1486846.html
 *
 */


#include<iostream>
#include "regexpr2.h"
#include<fstream>

using  namespace std;
using  namespace regex;

#pragma comment(lib, "Greta.lib")

int main()
{
    match_results results;
	ifstream fileStream("IP.txt");
	if(!fileStream)
	{
		cout << "file open failded!" << endl;
		return 0;
	}

	string str = "";
	getline(fileStream, str);
	fileStream.close();
    //string str = "0.0.0.256 ";
    rpattern pat("((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])", GLOBAL | ALLBACKREFS);
    match_results::backref_type br = pat.match(str, results);
	if(br.matched)
	{
		match_results::backref_vector vec = results.all_backrefs();
		int a = results.cbackrefs();
		for(int i = 0; i < a; i+=4)//the reason "+4", try i++, you wil know. I don't know why.
		{
			cout << vec[i] << endl;
		}
	}
	else
		cout << "error" << endl;
/*	cout << a << endl;
	match_results::backref_vector::iterator iter;
    if(br.matched)
	{
		for(iter = vec.begin(); iter != vec.end(); iter++)
		{
			string strtemp = (*iter).str();
			cout << strtemp << endl;
		}
    }*/
	return 0;
}
