//�����򣺽���������ر���ʱ�򣬲���ȫ��װ���ڴ�
#include <iostream>
using namespace std;

void heapifymin(int array[], int i, int size){
	if(i<size){
		int left=2*i+1;
		int right=2*i+2;
		int smallest=i;
		// �ҵ���С�ڵ�
		if(left<size){
			if(array[smallest]>array[left])
				smallest=left;
		}
		if(right<size){
			if(array[smallest]>array[right]){
				smallest=right;
			}
		}
		// ��ʼ���ڵ����С���ӽڵ㻥��
		if(smallest!=i){
			int temp=array[smallest];
			array[smallest]=array[i];
			array[i]=temp;
			// �������Ե�ǰ��С�ڵ�Ϊ���ڵ�
			heapifymin(array, smallest, size);
		}
	}
}
// ������С�Ѵ����һ���ڵ㿪ʼ����
void min_heapify(int array[], int size){
	for(int i=size-1;i>=0;i--)
		heapifymin(array,i,size);
}

void findmax(int array[], int k, int size, int kMax[]){
	for(int i=0;i<k;i++)
		kMax[i]=array[i];
	// ������
	min_heapify(kMax,k);
	cout<<"��С��������ʾ��"<<endl;
	for(int i=0;i<k;i++)
		cout<<kMax[i]<<" ";
	cout<<endl;
	for(int j=k;j<size;j++){
		// ������ڶ�����С�������򽻻�
		if(array[j]>kMax[0]){
			int temp=kMax[0];
			kMax[0]=array[j];
			array[j]=temp;
			// ����������ƻ���С�ѽṹ�����Ҫ���µ�����С��
			min_heapify(kMax,k);
		}
	}
}

int main(){
	int a[]={10,23,8,2,52,35,7,1,12};
	int length=sizeof(a)/sizeof(int);
	int k=4;
	int* kMax=new int[k];
	findmax(a,k,length,kMax);
	cout<<"����"<<k<<"����������ʾ��";
	for(int i=0;i<k;i++)
		cout<<kMax[i]<<" ";
	cout<<endl;
	return 0;
}


