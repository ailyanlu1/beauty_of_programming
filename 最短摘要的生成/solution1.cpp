#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;

pair<deque<string>,int> shortest_abstract(vector<string> word, vector<string> keyword){
	//��W����ĵڸ�λ�ÿ�ʼ����һ�ΰ������йؼ�������Q������
	
	map<deque<string>,int> dseq_map;
	bool flag=false;
	for(vector<string>::iterator w_index1=word.begin();w_index1!=word.end();w_index1++){
		vector<string> temp=keyword;
		deque<string> dseq;
		for(vector<string>::iterator w_index2=w_index1;w_index2!=word.end();w_index2++){
			if(keyword.empty()){
				keyword=temp;
			}
			for(vector<string>::iterator k_index=keyword.begin();k_index!=keyword.end();k_index++){
				
				//true��ʾword���ҵ�һ��keyword�����п�ʼ����
				if((*w_index2)==(*k_index)&&flag==false){
					flag=true;
					dseq.push_back((*w_index2));
					keyword.erase(find(keyword.begin(),keyword.end(),*w_index2));
					if(keyword.empty()){
						flag=false;
						//��dseq����dseq_map,����dseq�Ĵ�С
						dseq_map.insert(pair<deque<string>, int>(dseq,dseq.size()));


					}
					break;

				}
				else if(flag==true&&(*w_index2)!=(*k_index)){
					dseq.push_back(*w_index2);
					break;
				}
				else if(flag==true&&(*w_index2)==(*k_index)){
					dseq.push_back(*w_index2);
					keyword.erase(find(keyword.begin(),keyword.end(),*w_index2));
					if(keyword.empty()){
						flag=false;
						//��dseq����dseq_map,����dseq�Ĵ�С
						dseq_map.insert(pair<deque<string>, int>(dseq,dseq.size()));
					}
					break;
				}
			}
		}
		keyword=temp;
	}
	int min=INT_MAX;
	deque<string> min_seq;
	for (map<deque<string>,int>::iterator index=dseq_map.begin();index!=dseq_map.end();index++)
	{
		if(min>index->second){
			min=index->second;
			min_seq=index->first;
		}
	}
	pair<deque<string>,int> result;
	result=make_pair(min_seq,min);
	return result;
}

int main(){
	vector<string> W;
	vector<string> KeyWord;
	pair<deque<string>,int> Shortest_Abstract;
	// �ٶ���������Ϊ:ab bc cd cd be ac ad ac������keywordΪcd ac����ôӦ�÷��ص����ժҪӦ����cd be ac 
	W.push_back("ab");
	W.push_back("bc");
	W.push_back("cd");
	W.push_back("cd");
	W.push_back("be");
	W.push_back("ac");
	W.push_back("ad");
	W.push_back("ac");

	KeyWord.push_back("cd");
	KeyWord.push_back("ad");
	KeyWord.push_back("ac");
	Shortest_Abstract=shortest_abstract(W,KeyWord);
	cout<<"������Ϊ"<<endl;
	for(vector<string>::iterator index=W.begin();index!=W.end();index++){
		cout<<*index<<"	";
	}
	cout<<endl;
	cout<<"�ؼ�������"<<endl;
		for(vector<string>::iterator index=KeyWord.begin();index!=KeyWord.end();index++){
		cout<<*index<<"	";
	}
	cout<<endl;
	cout<<"���ժҪ����Ϊ"<<Shortest_Abstract.second<<endl;
	cout<<"���ժҪ�ǣ�"<<endl;
	deque<string> min_abstract=Shortest_Abstract.first;
	for (deque<string>::iterator index=min_abstract.begin();index!=min_abstract.end();index++)
	{
		cout<<*index<<"	";
	}
	return 0;
}