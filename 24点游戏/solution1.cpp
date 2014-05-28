#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<ctime>
using namespace std;

//cards[i]��ֵ��ͨ�����ʽexpr[i]�������
//��expr�����һ���������lastop[i]
bool GameRecur(double cards[], string expr[], char lastop[],
	const int cardsNum, const int result)
{
	if(cardsNum == 1)
	{
		if(cards[0] == result)
		{
			//cout<<expr[0]<<endl;
			return true;
		}
		else return false;
	}
	//������������ѡ����,����õ��м��������Һ�ʣ�����һ�����cards�����ǰ
	//cardsNum-1��λ��
	map<pair<double,double>,bool> selectedPair;
	for(int i = 0; i<cardsNum; i++)
	{
		for(int k  = i+1; k < cardsNum; k++)
		{
			// ����Ĵ���û�п���
			if( selectedPair.find(pair<double, double>(cards[i], cards[k]))
				!= selectedPair.end() || selectedPair.find(pair<double, double>
				(cards[k], cards[i])) != selectedPair.end() )//����ʹ��find���������صĶ�Ӧ��λ�ã�ֻҪ��Ӧ��λ�ò���end��˵�����д��ڣ��������˼����selectedPair�������ظ���cards
				break;
			else
			{
				selectedPair[pair<double,double>(cards[i], cards[k])] = 1;//1˵������û���ظ��ĵ�
				selectedPair[pair<double,double>(cards[k], cards[i])] = 1;
			}
			//����Ĵ��뱣֤ѡ�������Բ��ظ�
			double a = cards[i], b = cards[k];
			cards[k] = cards[cardsNum-1];
			string expra = expr[i], exprb = expr[k];
			expr[k] = expr[cardsNum-1];
			char lastop_a = lastop[i], lastop_b = lastop[k];
			lastop[k] = lastop[cardsNum-1];

			cards[i] = a + b;
			expr[i] = expra + '+' + exprb;
			lastop[i] = '+';
			if(GameRecur(cards, expr, lastop, cardsNum-1, result))
				return true;

			cards[i] = a - b;
			if('+' == lastop_b || '-' == lastop_b)
				expr[i] = expra + '-' + '(' + exprb + ')';
			else expr[i] = expra + '-' + exprb;
			lastop[i] = '-';
			if(GameRecur(cards, expr, lastop, cardsNum-1, result))
				return true;

			if(a != b)
			{
				cards[i] = b - a;
				if('+' == lastop_a || '-' == lastop_a)
					expr[i] = exprb + '-' + '(' + expra + ')';
				else expr[i] = exprb + '-' + expra;
				lastop[i] = '-';
				if(GameRecur(cards, expr, lastop, cardsNum-1, result))
					return true;
			}

			cards[i] = a * b;
			if('-' == lastop_a || '+' == lastop_a)
				expr[i] = '(' + expra + ')' + '*';
			else expr[i] = expra + '*';
			if('*' == lastop_b || ' ' == lastop_b)
				expr[i] += exprb;
			else expr[i] += '(' + exprb + ')';
			lastop[i] = '*';
			if(GameRecur(cards, expr, lastop, cardsNum-1, result))
				return true;

			if(b != 0)
			{
				cards[i] = a / b;
				if('-' == lastop_a || '+' == lastop_a)
					expr[i] = '(' + expra + ')' + '/';
				else expr[i] = expra + '/';
				if(' ' == lastop_b)
					expr[i] += exprb;
				else expr[i] += '(' + exprb + ')';
				lastop[i] = '/';
				if(GameRecur(cards, expr, lastop, cardsNum-1, result))
					return true;
			}

			if(a != 0 && a!= b)
			{
				cards[i] = b / a;
				if('-' == lastop_b || '+' == lastop_b)
					expr[i] = '(' + exprb + ')' + '/';
				else expr[i] = exprb + '/';
				if(' ' == lastop_a)
					expr[i] += expra;
				else expr[i] += '(' + expra + ')';
				lastop[i] = '/';
				if(GameRecur(cards, expr, lastop, cardsNum-1, result))
					return true;
			}

			//��ѡ�������������Ż�ԭλ
			cards[i] = a;
			cards[k] = b;
			expr[i] = expra;
			expr[k] = exprb;
			lastop[i] = lastop_a;
			lastop[k] = lastop_b;
		}
	}
	return false;
}

//cards �������
//cardsNum �Ƶ���Ŀ
//result ��Ҫ����õ��Ľ��
const int cardsNum=4;
string PointGame(int cards[], const int result)
{
	string expr[cardsNum];
	char lastop[cardsNum];
	double cardsCopy[cardsNum];
	for(int i = 0; i < cardsNum; i++)
	{
		char buf[30];
		sprintf(buf, "%d", cards[i]);
		expr[i] = buf;
		lastop[i] = ' ';//��ʾcardsCopy[i]�ǲ������κ������ԭʼ����
		cardsCopy[i] = cards[i];
	}
	if(GameRecur(cardsCopy, expr, lastop, cardsNum, result))
		return expr[0];
	else return "-1";
}


int main(){
	int cards[4]={11,8,3,5};
	cout<<PointGame(cards,24);
}