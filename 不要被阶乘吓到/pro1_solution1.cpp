// 算法部分见readme的12部分
#include <iostream>
using namespace std;
int count_5(int N){//即N！的末尾0的个数
	int count=0;
	for (int i=1;i<=N;i++)
	{
		int j=i;
		while(j%5==0){
			count++;
			j=j/5;
		}
	}
	return count;
}


int main(){
	int N=21;
	cout<<"The num of the 0 at the end 21!:"<<count_5(N)<<endl;
}
