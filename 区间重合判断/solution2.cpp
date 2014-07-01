#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ��������ݽṹ
class section
{
public:
	int begin,end;
};

bool comp(section s1, section s2){
	return s1.begin<s2.begin;
}

vector<section> mix(vector<section> dst){
	vector<section> no_insertion;
	section temp;
	bool flag=false;
	// �ϲ������ɸ����ཻ������
	for(vector<section>::iterator index=dst.begin();index!=dst.end()-1;index++){
		// �ཻ
		if(flag==false&&(*index).end>=(*(index+1)).begin){
			temp.begin=(*index).begin;
			temp.end=(*(index+1)).end;
			flag=true;
			continue;
		}
		if(flag==true&&temp.end>=(*(index+1)).begin){
			temp.end=(*(index+1)).end;
			flag=true;
		}
		// ���ཻ
		else if(flag){
			no_insertion.push_back(temp);
			no_insertion.push_back(*(index+1));
			flag=false;
		}
		else{
			no_insertion.push_back(*index);
		}

	}
	if(flag){
		no_insertion.push_back(temp);
	}
	return no_insertion;
}

bool is_coincide(section src,vector<section> dst){
	// ������	
	sort(dst.begin(),dst.end(),comp);
	vector<section> no_insertion=mix(dst);

	// ��no_sertion �в����Ƿ����src(����ʹ�ö��ַ�)
	for(vector<section>::iterator index=no_insertion.begin();index!=no_insertion.end();index++){
		if((*index).begin<=src.begin&&(*index).end>=src.end){
			return true;
		}
	}
	




	return false;

}

int main(){
	section src,temp;
	src.begin=10;
	src.end=11;
	vector<section> dst;
	temp.begin=2;
	temp.end=3;
	dst.push_back(temp);
	temp.begin=1;
	temp.end=2;
	dst.push_back(temp);
	temp.begin=3;
	temp.end=9;
	dst.push_back(temp);
	cout<<"is coincide?:"<<is_coincide(src,dst);
}