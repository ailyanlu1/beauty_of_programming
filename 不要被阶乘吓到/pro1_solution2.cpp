// �㷨���ּ�readme��12����
#include <iostream>
using namespace std;
int count_5(int N){//��N����ĩβ0�ĸ���
	int count=0;
	while(N){
		count+=N/5;
		N/=5;
	}
	return count;
}


int main(){
	int N=21;
	cout<<"The num of the 0 at the end 21!:"<<count_5(N)<<endl;
}
