#include <iostream>
#include <time.h>
using namespace std;

int* random(int max,int num){
	int *random_num=new int[num];
	srand((unsigned)time(NULL));
	for(int i=0;i<num;i++){
		random_num[i]=rand()%max;
	}
	return random_num;
}

void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
int RandomInRange(int min, int max)
{
	int random = rand() % (max - min + 1) + min;
	return random;
}

int Partition(int data[], int length, int start, int end)
{
	if(data == NULL || length <= 0 || start < 0 || end >= length)
		throw new std::exception("Invalid Parameters");

	int index = RandomInRange(start, end);//���ȥһ���±꣬���±��Ӧ���ִ����һ�ߣ�С������һ��
	Swap(&data[index], &data[end]);//���±��Ӧ��ֵ��Ϊ�жϴ�С��Ӧ��׼�����֣���swap����󣬷���Ա�

	int big = start - 1;
	for(index = start; index < end; ++ index)
	{
		if(data[index] > data[end])
		{
			++ big;
			if(big != index)//����������Ϊ������data[index]>data[end]ʱ��bigͣ������һ���������������������һ����������ʱ��big!=index����
							//����Ҫ�������ǵ�index��big��Ӧ����������672154��ǰ�����������if�飬���Ǿ���2��1֮��big=1,index=4������ʱ����
							// data[index]>data[end]��big++���轻��2��5������ǰ��Ĵ���4(������end)�������С��4����Ϊ675124
				Swap(&data[index], &data[big]);
		}
	}

	++ big;
	Swap(&data[big], &data[end]);// ������Ӧ��big��������end�����ּ����յõ�675412

	return big;
}

void find_k_num_solution2(int* input, int n, int* output, int k)
{
	if(input == NULL || output == NULL || k > n || n <= 0 || k <= 0)
		return;

	int start = 0;
	int end = n - 1;
	int index = Partition(input, n, start, end);
	while(index != k - 1)
	{
		if(index > k - 1)
		{
			end = index - 1;
			index = Partition(input, n, start, end);
		}
		else// С��k-1�Ĳ���
		{
			start = index + 1;
			index = Partition(input, n, start, end);
		}
	}

	for(int i = 0; i < k; ++i)
		output[i] = input[i];
}


int main(){
	int *random_num;
	int n=200,max=100,k=10;
	random_num=random(max,n);
	int* output=new int[k];
	find_k_num_solution2(random_num,n,output,k);
	for(int i=0;i<k;i++){
		cout<<output[i]<<" ";
	}
	cout<<endl;
	return 1;

}