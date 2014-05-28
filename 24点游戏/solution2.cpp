#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<ctime>
using namespace std;

struct setNode
{
	double val;
	string expr;//�����val�ı��ʽ
	setNode(double v, string e):val(v),expr(e){}
	setNode(double v, char e[]):val(v),expr(e){}
	bool operator < (const setNode &s)const
	{
		return val < s.val;
	}
};

void f(const int i, set<setNode> s[], const double result)
{
	int len = sizeof(s)/sizeof(set<setNode>) - 1;//len = 2^n - 1
	if(s[i].empty() == true)
		for(int x = 1; x <= i/2; x++)
			if((x&i) == x)
			{
				set<setNode>::iterator it1, it2;
				// s[i] U= fork(s[x] ,s[i-x])
				for(it1 = s[x].begin(); it1 != s[x].end(); it1++)
					for(it2 = s[i-x].begin(); it2 != s[i-x].end(); it2++)
					{
						string expr;
						double tempresult;
						tempresult = it1->val + it2->val;
						expr = '(' + it1->expr + '+' + it2->expr + ')';
						s[i].insert(setNode(tempresult, expr));
						//����f[2^n-1]ʱ����������˽�������ֹͣ
						if(i == len && tempresult == result)return;


						tempresult = it1->val - it2->val;
						expr = '(' + it1->expr + '-' + it2->expr + ')';
						s[i].insert(setNode(tempresult, expr));
						if(i == len && tempresult == result)return;
						if(it1->val != it2->val)
						{
							tempresult = it2->val - it1->val;
							expr = '(' + it2->expr + '-' + it1->expr + ')';
							s[i].insert(setNode(tempresult, expr));
							if(i == len && tempresult == result)return;
						}

						tempresult = it1->val * it2->val;
						expr = '(' + it1->expr + '*' + it2->expr + ')';
						s[i].insert(setNode(tempresult, expr));
						if(i == len && tempresult == result)return;

						if(it2->val != 0)
						{
							tempresult = it1->val / it2->val;
							expr = '(' + it1->expr + '/' + it2->expr + ')';
							s[i].insert(setNode(tempresult, expr));
							if(i == len && tempresult == result)return;
						}
						if(it1->val != it2->val && it1->val != 0)
						{
							tempresult = it2->val / it1->val;
							expr = '(' + it2->expr + '/' + it1->expr + ')';
							s[i].insert(setNode(tempresult, expr));
							if(i == len && tempresult == result)return;
						}
					}
			}
}

string PointGame2(int cards[], const int cardsNum, const int result)
{
	int len = 1<<cardsNum;
	set<setNode> S[len]; //��Ӧ�����е�����S
	//��ʼ��ֻ��һ��Ԫ�ص��Ӽ���j = 2^i����ֻ��һ��2����λ��1
	for(int i = 0, j = 1; i < cardsNum; i++, j = j<<1)
	{
		char buf[30];
		sprintf(buf, "%d", cards[i]);
		S[j].insert(setNode(cards[i],buf));
	}
	for(int i = 1; i <= len - 1; i++)
		f(i, S, result);
	for(set<setNode>::iterator it = S[len-1].begin();
		it != S[len-1].end(); it++)
	{
		if(it->val == result)
			return it->expr;
	}
	return "-1";
}