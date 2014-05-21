#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//�����ҳ�������һ�ε�ID��ÿ��ID��С��10e��������ID�б������data.txt�У�IDһ���ǳɶԳ��֣�
//�����Ƴ�������ҳ��Ǹ�������һ�ε�ID
//�㷨�������е�ID������������X���X=0��X���0=X�����õ������ּ�Ϊ������һ�ε�ID


// 1�����һ����txt�������ݵĺ�������Ϊid��С��10e��������������Ϊlong long��
// ע��� ����vector<long long>&����ֵ����ʱ�����ܺ����ڲ���ֵ����vector�����ں����뿪֮��ỹԭ��ʹ��&�����򲻻�
int read_from_txt(const char* file_path,vector<long long> &l_vec){
	ifstream fin(file_path);
	if(!fin)
	{
		cerr<<"Can't open"<<file_path<<endl;
		return -1;
	}
	while(!fin.eof()){
		long long ltemp;
		fin>>ltemp;
		l_vec.push_back(ltemp);
	}
	fin.close();
	return 1;
	
}

long long fast_find_num_once(vector<long long> & l_vec){
	long long xor=0;
	for(vector<long long>::iterator index=l_vec.begin();index!=l_vec.end();index++)
	{
		xor=xor^(*index);
	}
	return xor;
}
// ���������¼ID����˫�����ݣ���ÿ����¼���ļ�����������¼���ʧһ����¼�����������ҽ�����һ�ε�ID����fast_find_num_once�Ĺ���
// ���ǿ��ܶ�ʧ������¼
// ��ʧ��¼��������֣�1��������¼ǡ����ȫ��ͬ��Ҳ����˵���ڼ�¼�ļ�������������Ϊ0��
// 2������һ���ǣ�������¼��ͬ��Ҳ����˵��������ֻ����һ�εļ�¼����ô����ҳ�������ֻ
// ����һ�εļ�¼�أ��������ܶ����м�¼������Ϊ0�������бض���ĳλΪ1�����ǲ����ݴ�
// ��ԭ�����ݷ�Ϊ��������λΪ1�����λ��Ϊ1�ģ�Ȼ��ֱ������������������õ�������
// ¼����һ�ε�ID
int fast_find_ID_lost_twice(vector<long long> & l_vec,long long &x_A,long long &x_B){
	if(l_vec.empty())
		return 0;
	long long xor=fast_find_num_once(l_vec);
	//������������ʧ�Ĳ�����ͬ��¼,�ҵ�xor��λ�ϵ�һ��Ϊ1�ģ����������ʧ��Ϊ��ͬ��¼����
	if(xor==0){
		// ��������ID֮��-����������������ID֮��
		// x_A=x_B=(sum-sum_current)/2;
		// ��Ϊ�����Ǻܴ������ӣ��漰��������ӵ��㷨��һ�������Ӳ���λ�ķ��������������ӵ�
		// ������ʱ������ ǰ�濴���ʱ�����漰����
	}
	else{
	int k=0;
	while(xor){
		if(xor%2==1)
			break;
		k++;
		xor=xor>>1;
	}
	for(vector<long long>::iterator index=l_vec.begin();index!=l_vec.end();index++){
		if ((*index>>k)%2==0)
		{
			x_A=x_A^(*index);
		}
		else
			x_B=x_B^(*index);
	}
	return 1;
	}
}

int main(int argc,char * argv[]){
	//char* file_path="data.txt";
	char* file_path="data2.txt";
	vector<long long> long_vec;
	if(read_from_txt(file_path,long_vec)!=1){
		cerr<<"error happened!"<<endl;
	}

	// ����txt�ı����ݴ��뵽long_vec��
	//cout<<"The num appear once is :"<<fast_find_num_once(long_vec)<<endl;
	long long x_A=0;
	long long x_B=0;
	fast_find_ID_lost_twice(long_vec,x_A,x_B);
	cout<<"The num appear once is :"<<x_A<<" and "<<x_B<<endl;

}