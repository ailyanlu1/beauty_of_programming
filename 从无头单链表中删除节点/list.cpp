#include <iostream>
#include "list.h"
using namespace std;



//����ͷ���
void List::create_List()
{
	head = new Node(0);
}
//��β������һ���ڵ�
void List::insert(const int& d)
{
	
	//p->next = head->next;
	//head->next = p;
	Node* p=head;
	while(p->next){
		p=p->next;
	}
	Node *temp = new Node(d);
	p->next=temp;
	temp->next=NULL;
}
//��ӡ����
void List::print()
{
	for(Node * p = head->next;p;p=p->next){
		cout << p->data << endl;
	}
}
//��dλ��֮ǰ����d1
void List::insert_pos(const int& d,const int& d1)
{
	Node * p = find(d);
	Node * q = new Node(d1);
	q->next = p->next;
	p->next = q;
}

//ɾ��
void List::erase(const int& d)
{
	Node * p = find(d);
	//��Ϊp����һ���ڵ��λ�ã���q������
	//Ҫɾ���Ľڵ�ĵ�ַ
	Node *q = p->next;
	//ͨ������һ���ڵ��nextָ��ָ��Ҫɾ���ڵ��nextָ
	//��־��Ľڵ�ʵ�ֶϿ�Ҫɾ���ڵ��Ŀ��
	p->next = p->next->next;
	//ɾ��Ҫɾ���Ľڵ�q
	delete q;
}

void List::erase_without_head(Node* pCurrent){
	Node* pNext=pCurrent->next;
	pCurrent->next=pNext->next;
	pCurrent->data=pNext->data;
	delete pNext;
}

//�޸�ָ������
void List::updata(const int& d,const int& d1)
{
	Node * p = find(d);
	p->next->data = d1;
}

////��ת����
//void List::reverse()
//{
//	Node * p = head->next;//ͷ���֮��ĵ�1���ڵ�
//	Node * q = head->next->next;//ͷ���֮��ĵ�2�ڵ�
//	Node * m = head->next->next->next;//ͷ���֮��ĵ�3���ڵ�
//	p->next = NULL;//��ͷ�ӵ�֮��ĵ�1���ڵ��nextָ����Ϊ��
//	//����m�Ƿ�Ϊ�����ж� �Դ�����ÿһ���ڵ�
//	while(m){
//		q->next = p;
//		p = q;
//		q = m;
//		m = m->next;
//	}
//	//�����һ���ڵ�����
//	q->next = p;
//	//��ͷ����ָ���µĵĵ�1���ڵ�(֮ǰ�����һ���ڵ�)
//	head ->next = q;
//}