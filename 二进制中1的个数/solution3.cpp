#include <iostream>
using namespace std;

int count(int num){
	int count=0;
	while(num){
		num&=(num-1);//ÿһ���ҵ���Ӧ�����λ1
		count++;
	}
	return count++;
}


int main(){
	int num=21;
	cout<<"The # of 1 in the "<<num<<" is :"<<count(num)<<endl;
	return 1;
}