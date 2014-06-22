// ���������readme21�㷨��
// ����˵�������迼������ĵ�һ��Ԫ��A[0]���Լ�����һ������(A[i],...,A[j])��A[0]֮��Ĺ�ϵ
// 1,��0=i=jʱ��Ԫ��A[0]�����ɺ�����һ��
// 2,��0=i<jʱ��������һ�δ�A[0]��ʼ��
// 3,��0<iʱ��Ԫ��A[0]��������һ��û�й�ϵ

#include <iostream>
using namespace std;

int max(int x,int y){
	return (x>y)? x:y;
}
// ��Ҫ������������ռ�
int MaxSum(int *A, int n){
	int* start=new int[n];
	int* all=new int[n];
	start[n-1]=A[n-1];
	all[n-1]=A[n-1];
	for(int i=n-2;i>=0;i--){
		start[i]=max(A[i],A[i]+start[i+1]);
		all[i]=max(start[i],all[i+1]);
	}
	return all[0];
}
// ����Ҫ��������
int MaxSum2(int *A, int n){
	int nstart=A[n-1];
	int nAll=A[n-1];
	for(int i=n-2;i>=0;i--){
		nstart=max(A[i],nstart+A[i]);
		nAll=max(nstart,nAll);
	}
	return nAll;
}

int main(){
	int a[]={1,-2,3,5,-3,2};
	cout<<"The max sum is :"<<MaxSum(a,sizeof(a)/sizeof(int))<<"	"<<MaxSum2(a,sizeof(a)/sizeof(int));
	return 0;
}
