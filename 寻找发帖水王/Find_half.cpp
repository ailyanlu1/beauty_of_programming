#include <iostream>
using namespace std;

//�ٶ�ID����Ϊint
// find()��candidate����id�г���һ��ģ�ʹ��nTimes������ڴ�������ͬ����������ͬ�Ļ���,��γ�����߼�����
// ÿ��ɾ����ͬ�ģ������ڳ���ı�д�ϲ�û�����ɾ�����ݣ���������һ��candidate�Ͷ�Ӧ��nTimes��ģ���Ӧ�Ĺ���
// Ҳ����forѭ���Ĺ���
int find(int* id, int N){
	int candidate;
	int nTimes,i;
	for(i=nTimes=0;i<N;i++){
		if(nTimes==0){
			candidate=id[i],nTimes=1;
		}
		else{
			if(candidate==id[i]){
				nTimes++;
			}
			else
				nTimes--;
		}
	}
	return candidate;
}

int main(){
	int a[]={1,2,3,4,5,1,1,1,1,1};
	cout<<"The half more num is :"<<find(a,sizeof(a)/sizeof(int));
	return 1;
}
