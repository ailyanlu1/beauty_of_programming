//����������2�ĸ�������N��ȥN�Ķ����Ʊ�ʾ��1�ĸ���
// �㷨���ּ�readme��12����
#include <iostream>
using namespace std;

int count_bin_1(int num){
	int count=0;
	while(num){
		num&=(num-1);//ÿһ���ҵ���Ӧ�����λ1
		count++;
	}
	return count;
}

int count_2(int N){//��N����ĩβ0�ĸ���
	int count=0;
	count=N-count_bin_1(N);
	return count;
}


int main(){
	int N=21;
	cout<<"The num of the binary 0 at the end 21!:"<<count_2(N)<<endl;
}
