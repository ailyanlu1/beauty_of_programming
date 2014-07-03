struct Node{
	int data;
	Node * next;
	Node(const int& d):data(d),next(NULL){}
};

class List {
public:
	List(){create_List();}
	~List(){clear();}
	//����ͷ���
	void create_List();
	//���뺯��
	void insert(const int& d);
	//��ָ��λ�ò���
	void insert_pos(const int& d,const int& d1);
	//ɾ��ָ�����ݵĽڵ�
	void erase(const int& d);
	void erase_without_head(Node* pCurrent);
	//�޸�ָ������
	void updata(const int& d,const int& d1);
	////��ת������
	//void reverse();
	Node * head;
	//��ӡ
	void print();
private:
	//�ڵ�ṹ
	
	//ͷ�ڵ�
	//����������
	void clear(){
		Node * p = head;
		//��ͷ�ڵ㿪ʼѭ��ɾ��
		while(p){
			Node * q = p->next;
			delete p;
			p = q;
		}
	}
	//��������d����һ���ڵ�λ�õĺ���
	//Ϊ�˷������ɾ������
	Node* find(const int& d){
		Node * p = head;
		for(;p;p=p->next){
			if(p->next->data==d)
				break;
		}
		return p;
	}
};