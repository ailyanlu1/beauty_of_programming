#include <iostream>
#include "list.h"
using namespace std;


int main(){
	List al;
	al.insert(2);
	al.insert(3);
	al.insert(4);
	al.insert(5);

	cout<<"������������Ϊ"<<endl;
	al.print();

	Node* pCurrent;
	pCurrent=al.head;
	pCurrent=pCurrent->next->next;
	cout<<"ָ��ָ�������Ϊ��";
	cout<<pCurrent->data<<endl;
	al.erase_without_head(pCurrent);
	al.print();
	return 0;


}