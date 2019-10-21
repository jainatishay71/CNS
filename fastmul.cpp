#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a,b,c="00011011";
	cin>>a>>b;
	cout<<endl;
	string cur=a;
	string str[8];
	str[0]=a;
	for(int w=1;w<8;w++)
	{
		string r="";
		int q=0;
		if(cur[0]=='1')
			q=1;
		for(int j=1;j<8;j++)
		{
			r+=cur[j];
		}
		r+="0";
		if(q)
		{
			for(int i=0;i<8;i++)
			{
				int y1,y2,y3;
				if(r[i]=='0')
					y1=0;
				else
					y1=1;
				if(c[i]=='0')
					y2=0;
				else
					y2=1;
				y3=y1^y2;
				if(y3==0)
					r[i]='0';
				else
					r[i]='1';
			}
		}
		cur=r;
		str[w]=r;
	}
	for(int i=0;i<8;i++)
	{
		cout<<str[i]<<endl;
	}
	cout<<endl;
	string res="00000000";
	for(int j=0;j<8;j++)
	{
		if(b[j]=='1')
		{
			for(int i=0;i<8;i++)
			{
				int y1,y2,y3;
				if(str[7-j][i]=='0')
					y1=0;
				else
					y1=1;
				if(res[i]=='0')
					y2=0;
				else
					y2=1;
				y3=y1^y2;
				if(y3==0)
					res[i]='0';
				else
					res[i]='1';
			}
		}
	}
	cout<<res<<endl;
}