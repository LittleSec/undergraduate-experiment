/* quoto0: http://www.cnblogs.com/giszhang/archive/2009/05/22/1486846.html
 *
 */


#include<iostream>
#include "regexpr2.h"
#include<fstream>
#include<vector>
#include<string>

using  namespace std;
using  namespace regex;

#pragma comment(lib, "Greta.lib")

int a;

typedef struct{
	int lineNum;
	string href;
}printResultFormat;


int main()
{
    match_results results;
	vector<printResultFormat>hrefBuff;

	ifstream fileStream("main.html");
	if(!fileStream)
	{
		cout << "file open failded!" << endl;
		return 0;
	}

	int lineCount = 0;
	match_results aTagResult;
	rpattern aTagPat("\\<a.*href=.*\\>");
	rpattern hrefPat("(href=\"([^\"]+)\")|(href='([^']*)')");

	string str = "";
	while(getline(fileStream, str))
	{
		lineCount++;
		match_results::backref_type br = aTagPat.match(str, aTagResult);
		if(br.matched)
		{
			string atemp = br.str();
			match_results hrefResult;
			match_results::backref_type gethref = hrefPat.match(atemp, hrefResult);
			if(gethref.matched)
			{
				printResultFormat temp;
				temp.href = gethref.str();
				temp.lineNum = lineCount;
				hrefBuff.push_back(temp);
			}
		}
	}

	fileStream.close();


	for(int i = 0; i < hrefBuff.size(); i++)//the reason "+4", try i++, you wil know. I don't know why.
	{
		cout << hrefBuff[i].lineNum << "\t" << hrefBuff[i].href << endl;
	}

	//cout << "sum: " << hrefBuff.size() << endl;
/*
	vector<printResultFormat>::iterator iter = hrefBuff.begin();
    while(iter != hrefBuff.end())
	{
		cout << iter->lineNum << "\t" << iter->href << endl;
    }*/
	return 0;
}
