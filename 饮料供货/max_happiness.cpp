// ����������ָ����������������V������£�����ҵ����������
// ʹ�ö�̬�滮���Ժ����ɵؽ��������⣺
// �������������csdn��ĳλ���ѵģ���Ϊ�����Ŀ�ѶȲ��Ǻܴ�
// ��û���Լ�����д���Ͼ�дһ�㶫�����Ǻܻ�ʱ���

#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
#define V 64
#define N 7

int opt[V+1][N+1];
int v[N]={2,4,8,2,4,8,16};
int c[N]={3,2,1,3,2,4,1};
int h[N]={20,30,25,30,15,30,100};

int cal(int y,int i)
{
	if(i==N)
	{
		if(y==0)
			return 0;
		else
			return -10000;
	}
	if(y<0)
		return -10000;
	else if(y==0)
		return 0;
	else if(opt[y][i]!=-1)
		return opt[y][i];
	int ret=-10000;
	for(int t=0;t<=c[i];t++)
	{
		int temp=cal(y-t*v[i],i+1);
		if(temp!=-10000)
		{
			temp+=h[i]*t;
			if(temp>ret)
				ret=temp;
		}
	}
	opt[y][i]=ret;
	return opt[y][i];
}

//����¼��
void memo_fun()
{
	for(int i=0;i<=V;i++)
	{
		for(int j=0;j<N;j++)
		{
			opt[i][j]=-1;
		}
	}
	int cc=cal(V,1);
	cout<<"biggest happiness is "<<cc<<endl;
}

//��̬�滮��
void dynamic_fun()
{
	opt[0][N]=0;
	for(int q=0;q<=N;q++)
		opt[0][q]=0;
	for(int i=1;i<=V;i++)
		opt[i][N]=-10000;
	for(int j=N;j>=0;j--)
	{
		for(int i=1;i<=V;i++)
		{
			opt[i][j]=-10000;
			for(int k=0;k<c[j];k++)
			{
				if(i<k*v[j])
				{
					break;
				}
				int x=opt[i-k*v[j]][j+1];
				if(x!=-10000)
				{
					x+=h[j]*k;
					if(x>opt[i][j])
					{
						opt[i][j]=x;
					}
				}
			}
		}
	}
	cout<<"the biggest happiness is: "<<opt[V][0]<<endl;
}

int main()
{
	cout<<"��̬�滮�㷨ʵ��"<<endl;  
	dynamic_fun();  
	cout<<"����¼�㷨ʵ��"<<endl;  
	memo_fun();  
	system("pause");  
	return 0;  
}