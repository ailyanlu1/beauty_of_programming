// �������ĸ����ԣ��ֱ���ʱ���[1,5],[2,3],[3,4],[3,6],��ͬ��������ͬһʱ�䰲����ͬһ�����Ե�
#include <iostream>
using namespace std;
const int N=4;
struct Time{
	int begin;
	int end;
};

bool forbit[N];//��ֹ���飬Ϊfalseʱ����ʾ��ǰ����ɫ����ʹ��,
int maxcolors;

Time times[N];
int color[N]={0};
int cmp(const void * a, const void* b){
	return ((Time*)a)->begin-((Time*)b)->begin;
}

void init(){
	for(int i=0;i<N;i++){
		cin>>times[i].begin>>times[i].end;
	}
	qsort(times,N,sizeof(Time),cmp);
}

bool overlap(const Time &a ,const Time &b){
	if(b.begin>=a.begin&&b.begin<a.end){
		return true;
	}
	return false;
}

int arrange(){
	maxcolors=0;
	int i,j,k;
	for(i=0;i<N;i++){
		for(k=0;k<maxcolors;k++){
			forbit[k]=false;
		}

		//�ж���i֮ǰ�Ľڵ��Ƿ���i�ڵ����غϵĵط�
		for(j=0;j<i;j++){
			if(overlap(times[j],times[i])){//�����֮ǰ�����غϵ����䣬��ô������֮ǰ�Ǹ�����ɫ������ͬҲ�Ǿ���forbit[i]��true
				forbit[color[j]]=true;
			}
		}
		for(k=0;k<maxcolors;k++){
			if(!forbit[k])
				break;
		}
		if(k<maxcolors)
			color[i]=k;
		else
			color[i]=maxcolors++;
	}
	return maxcolors;
}


int main(){
	init();
	int max=arrange();
	cout<<max<<endl;
	return 0;
}

