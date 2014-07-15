//�ж������Ƿ��ཻ����ͨ���ж������Ƿ��л�����
#include <iostream>
using namespace std;

struct LinkList{
	int value;
	LinkList* next;
};

void InsertList(LinkList *&list){
	LinkList* head;
	LinkList* newNode;
	int data;
	head=list;
	while(head->next)
		head=head->next;

	while(1){
		cin>>data;
		if(data==0)break;
		newNode=new LinkList;
		if(!newNode)
			exit(0);
		newNode->value=data;
		newNode->next=NULL;
		head->next=newNode;
		head=newNode;
		head->next=NULL;
	}
}

void Traverse(LinkList* list){
	LinkList* p;
	p=list->next;
	while(p){
		cout<<" "<<p->value<<" address="<<p<<endl;
		p=p->next;
	}
}

int main(){
	LinkList *first,*second;
	LinkList *fhead,*shead,*h1,*h2,*p,*q;
	int flen=0,slen=0,len;
	first=new LinkList;
	first->next=NULL;
	second=new LinkList;
	second->next=NULL;
	InsertList(first);
	cout<<endl;
	InsertList(second);


	///////////////////////////////////////////////// 
	//����һ�������дӵ��ĸ���������ӵ��ڶ����������������ཻ������
	p=second;
	while(p->next)
		p=p->next;//�ҵ��ڶ��������β���

	q=first;
	for(int i=0;i<4;i++)
		q=q->next;//�ҵ���һ������ĵ��ĸ����
	p->next=q;//���뵽�ڶ���������
	//////////////////////////////////////////////////
	Traverse(first);
	cout<<endl;
	Traverse(second);
	cout<<endl;

	h1=first->next;
	fhead=first;
	while(fhead->next)//����������β ��ִ��length1�Σ���n2�Σ�

	{
		fhead=fhead->next;
		flen++;
	}

	h2=second->next;
	shead=second;
	while(shead->next)//����������β�� ��ִ��length2�Σ���n1�Σ�
	{
		shead=shead->next;
		slen++;
	}
	if(fhead==shead)//���һ�����ĵ�ַ��ͬ�����ཻ
	{ 
		cout<<"�������ཻ"<<endl;
		// �����ֵ���Ƚϳ����ȴ�ͷ������ֵ������
		if(flen>=slen)//�����������ȵĲ�ֵ
		{
			len=flen-slen;
			while(len--) //������ֵ������ ��ִ��abs(length1-length2)�Σ�

				h1=h1->next;  
		}
		else
		{
			len=slen-flen;
			while(len--)
				h2=h2->next; 
		}

		while(1)
		{

			if(h1==h2)//���������е�ַ��ͬ�Ľ��   �����ִ�еĴ���Ϊ��min(length1,length2))

			{
				cout<<"��һ���ཻ�Ľ�㣺"<<h1->value;
				break;
			}
			else if(h1->next&&h2->next)
			{
				h1=h1->next;
				h2=h2->next;
			} 
		}
	}
	else 
		cout<<"�������ཻ"<<endl;

} 