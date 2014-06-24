#include <iostream>
using namespace std;

int LIS(int d[], int n){
	int *B = new int[n];
	int i, left, right, mid, len = 1;
	B[0] = d[1]; //Ϊ�˺������һ�£����Ǵ� 1 ��ʼ������:)
	for(i = 2; i <= n; ++i){
		left = 0, right = len;
		while(left <= right){
			mid = (left + right) / 2;
			if(B[mid] < d[i]) left = mid + 1; //���ֲ��� d[i]�Ĳ���λ��
			else right = mid - 1;
		}
		B[left] = d[i]; //����
		if(left > len) len++; //d[i]�����е��������ֶ������� left �Ż���� len��
	}
	delete[] B;
	return len;
}


int main(){
	int array[]={1,-1,2,-3,4,-5,6,-7};
	cout<<"The length of the LIS is :"<<LIS(array,sizeof(array)/sizeof(int));
	return 0;
}