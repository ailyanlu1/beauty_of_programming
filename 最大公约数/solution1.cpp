//շת��f(x,y)=f(y,x%y),���ر�֤x>=y��Ϊ��x<yʱ��һ������ʱ��x=��һ�ε�y��y������һ�ε�x
#include <iostream>
using namespace std;
int gcd(int x, int y){
	return (!y)?x:gcd(y,x%y);
}

int main(){
	int x=30,y=42;
	int a=gcd(x,y);
	cout<< a<<endl;
}