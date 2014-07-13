#include<iostream>
#include<string>
#include<map>
#include<deque>
using namespace std;

void find_min_len_abstract(string str[], string keyword[], int len_str, int len_keyword) {
	// ��ʼ��map 
	map<string,int> record;
	for(int i=0; i<len_keyword; i++) {
		record[keyword[i]] = 0;
	}
	// ƥ�����
	deque<int> store; // �洢����str�йؼ��ʵĶ�Ӧ�±� 
	int min_len = 0;
	int min_index_first = -1;
	int min_index_last = -1;
	int find_key_num = 0;
	int index = 0;
	while(find_key_num < len_keyword && index < len_str) {
		if(record.find(str[index]) == record.end()) { // str[index]���ǹؼ��� 
			index++;
		}
		else { // str[index]�ǹؼ��� 
			if(record[str[index]] == 0) // ��һ���ҵ�����ؼ���
				find_key_num ++;
			record[str[index]] = record[str[index]] + 1; // ��Ӧ�ؼ��ʼ�����1
			store.push_back(index); 
			index++;
		}
	}
	// find_key_num��ʾ�Ѿ���str���ҵ�����Ŀ��len_keyword ��ʾ�ؼ��ʵĳ���
	if(find_key_num < len_keyword) { // һ�������ժҪ��û�ҵ� 
		cout << "not abstract found " << endl;
	}

	else { // �ҵ�һ���ˣ��������Ҹ��õ� 
		min_len = store.back()- store.front() + 1;   
		min_index_first = store.front();
		min_index_last = store.back();
		// ��һ��ժҪ 
		cout << "��һ��ժҪ" << endl; 
		cout << "min len: " << min_len << endl;
		for(int i=min_index_first; i<=min_index_last; i++)
			cout << str[i] << " ";
		cout << endl; 
		cout << "---------------------------------------------" << endl;
		string need_key;
		bool already_found = true;
		while(true) {   
			if(already_found == true) { // �պ��ҵ�һ����ժҪ 
				string first_key = str[store.front()];
				record[first_key]--; // ���ٵ�ǰ��ǰ��Ĺؼ��� 
				store.pop_front(); // �ؼ��ʳ��� 
				if(record[first_key] == 0) { // ����ùؼ���û�� 
					already_found = false;
					need_key = first_key; // ��¼��ҪѰ�ҵĹؼ��� 
				}               
				else { // ���˴�����ǻ��������йؼ��ʣ�˵������һ�����̵�ժҪ 
					min_len--;
					min_index_first ++;
					cout << "���̵�ժҪ" << endl;
					cout << "min len: " << min_len << endl;
					for(int i=min_index_first; i<=min_index_last; i++)
						cout << str[i] << " ";
					cout << endl; 
					cout << "---------------------------------------------" << endl;
				}
			}
			else { // ��Ҫ����������������Ĺؼ��� 
				if(index >= len_str) { // �������ҵ���Ҫ�Ĺؼ����� 
					break;
				}
				else if(record.find(str[index]) == record.end()) { // ���ǹؼ��� 
					index++;
				}
				else { // �ǹؼ��� 
					record[str[index]] = record[str[index]]+1;
					store.push_back(index); 
					if(str[index] == need_key) { // ���û�����Ҫ�ҵ��Ĺؼ���
						already_found = true;
						if((store.back()-store.front() + 1) < min_len) { // �µ�ժҪ���� 
							min_len = store.back() - store.front() + 1;
							min_index_first = store.front();
							min_index_last = store.back();
							// ���̵�ժҪ
							cout << "���̵�ժҪ" << endl;
							cout << "min len: " << min_len << endl;
							for(int i=min_index_first; i<=min_index_last; i++)
								cout << str[i] << " ";
							cout << endl; 
							cout << "---------------------------------------------" << endl;
						}
						else {
							cout << "���Ǹ��̵�ժҪ" << endl;
							cout << "min len: " << store.back() - store.front() + 1 << endl;
							for(int i=store.front(); i<=store.back(); i++)
								cout << str[i] << " ";
							cout << endl; 
							cout << "---------------------------------------------" << endl;
						}
					}
					index++; 
				} // else
			} // else
		} // while
	} // else
	// ������
}

int main() {  
	// string keyword[] = { "΢��", "�����", "����", "�й�"};
	string keyword[] = { "΢��", "�����", "����"};
	string str[] = { 
		"΢��","����","�о�Ժ","����","��","1998","��","��","����","��","ʹ��",
		"��","ʹ","δ��","��","�����","�ܹ�","��","��","��","��","ѧ","��",
		"��","��","��Ȼ����","��","����","����","����","��","��","��","����","��",
		"��","΢��","����","�о�Ժ","��","��","�ٽ�","�����","��","��̫","����",
		"��","�ռ�","��","����","��̫","�û�","��","����","����","��","��"
	};
	int len_keyword = sizeof(keyword)/sizeof(string);
	int len_str = sizeof(str)/sizeof(string);
	find_min_len_abstract(str, keyword, len_str, len_keyword);

	system("PAUSE");
	return 0;
}