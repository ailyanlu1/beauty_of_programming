#include <iostream>

using namespace std;

int candidate[3];
int count[3] = {0};

int input[100];
int num = 0;
/************************************************************************/
/* ˼·�����Ƶģ�ͬ����ÿ��ɾ��4����ͬ��ID����Ӱ�조������ID��ʣ��ID�г�����
Ȼ����1/4����һ��ʵ��������ǿ���ÿ��ɾ��4����ͬ��ID��ֱ��ʣ��3��IDΪֹ����
��������ô���֡�ɾ���ĸ���ͬID����һ�����أ������������ġ���candidate[3]��¼
������ѡID����count[3]��¼���ǵ��ۻ�������Ȼ���������ID�б�ÿ����һ��ID����
��candidate[i]�е�ĳһ����ͬ����count[i]++��������������ͬ����˵���ҵ����ĸ���
����ͬ��ID��������count[i]--��Ҳ���൱�ڡ�ɾ�����ĸ���ͬID������ĳһ��count[i]==0��
�����֮��֮ǰ����������ʱ��һֱû�����������Ҳ�й�����˼·ȴһֱ���ò���ȷ��
��μ򵥵Ĳ����˼������ݣ�ò��û�����⡣���д��󣬻�ӭָ����
�������£�                                                                     */
/************************************************************************/

int main()
{
	cout<<"please input"<<endl;
	int t;
	while(cin>>t)
	{
		if (t == -1)
			break;
		input[num++] = t;
	}

	bool flag = false;

	for (int i = 0;i < num;i++)
	{
		flag = false;
		for (int j = 0;j < 3;j++)
		{
			if (count[j] == 0)
			{
				continue;
			}
			if (candidate[j] == input[i])//��ѡ��������ڵ�ǰinput��
			{
				count[j]++;
				flag = true;
			}
		}

		if (flag == true)//�������洦�����Ҳ�����ͬ������һ�´���
		{
			continue;
		}

		for (int j = 0;j < 3;j++)
		{
			if (count[j] == 0)
			{
				candidate[j] = input[i];
				count[j]++;
				flag = true;
				break;
			}
		}

		if (flag == true)
		{
			continue;
		}

		for (int j = 0;j < 3;j++)
		{
			count[j]--;
		}

	}

	cout<<count[0]<<" "<<count[1]<<" "<<count[2]<<endl;
	cout<<candidate[0]<<" "<<candidate[1]<<" "<<candidate[2]<<endl;
}