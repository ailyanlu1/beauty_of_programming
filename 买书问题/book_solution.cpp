#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//������������⿴��һ����̬�滮���⣬״̬ת�Ʒ���Ϊ��
//F(Y1,Y2,Y3,Y4.Y5)=0  if(Y1=Y2=Y3=Y4=Y5=0)
//or F(Y1,Y2,Y3,Y4,Y5)=min{5*8*(1-25%)+F(Y1-1,Y2-1,Y3-1,Y4-1,Y5-1),
// 4*8*(1-20%)+F(Y1-1,Y2-1,Y3-1,Y4-1,Y5),
// 3*8*(1-10%)+F(Y1-1,Y2-1,Y3-1,Y4,Y5),
// 2*8*(1-5%)+F(Y1-1,Y2-1,Y3,Y4,Y5),
// 8+F(Y1-1,Y2,Y3,Y4,Y5)
float max_float=9999.0;

float min(float num1, float num2, float num3, float num4, float num5){
	vector<float> num_float;
	num_float.push_back(num1);
	num_float.push_back(num2);
	num_float.push_back(num3);
	num_float.push_back(num4);
	num_float.push_back(num5);
	sort(num_float.begin(),num_float.end());
	return num_float[0];
}
float func(vector<int> book_list){
	
	vector<int> book_list_copy=book_list;
	float sum1,sum2,sum3,sum4,sum5;
	
		//һ��4��
	if(book_list_copy[4]>=1){
		book_list_copy=book_list;
		for(vector<int>::iterator index=book_list_copy.begin();index!=book_list_copy.end();++index)
			(*index)-=1;
		sort(book_list_copy.begin(),book_list_copy.end(),greater<int>());
		sum5=5*8*0.75+func(book_list_copy);//�����ǶԵ�
		book_list_copy=book_list;
		for(vector<int>::iterator index=book_list_copy.begin();index!=book_list_copy.end()-1;++index)
			(*index)-=1;
		sort(book_list_copy.begin(),book_list_copy.end(),greater<int>());
		sum4=4*8*0.8+func(book_list_copy);//ok
		book_list_copy=book_list;
		for(vector<int>::iterator index=book_list_copy.begin();index!=book_list_copy.end()-2;++index)
			(*index)-=1;
		sort(book_list_copy.begin(),book_list_copy.end(),greater<int>());
		sum3=3*8*0.9+func(book_list_copy);
		book_list_copy=book_list;
		for(vector<int>::iterator index=book_list_copy.begin();index!=book_list_copy.end()-3;++index)
			(*index)-=1;
		sort(book_list_copy.begin(),book_list_copy.end(),greater<int>());
		sum2=2*8*0.95+func(book_list_copy);
		book_list_copy=book_list;
		for(vector<int>::iterator index=book_list_copy.begin();index!=book_list_copy.end()-4;++index)
			(*index)-=1;
		sort(book_list_copy.begin(),book_list_copy.end(),greater<int>());
		sum1=8+func(book_list_copy);
		return min(sum1,sum2,sum3,sum4,sum5);
		}
	else if(book_list_copy[3]>=1){
		book_list_copy=book_list;
		for(vector<int>::iterator index=book_list_copy.begin();index!=book_list_copy.end()-1;++index)
			(*index)-=1;
		sum4=4*8*0.8+func(book_list_copy);
		book_list_copy=book_list;
		for(vector<int>::iterator index=book_list_copy.begin();index!=book_list_copy.end()-2;++index)
			(*index)-=1;
		sort(book_list_copy.begin(),book_list_copy.end(),greater<int>());
		sum3=3*8*0.9+func(book_list_copy);
		book_list_copy=book_list;
		for(vector<int>::iterator index=book_list_copy.begin();index!=book_list_copy.end()-3;++index)
			(*index)-=1;
		sort(book_list_copy.begin(),book_list_copy.end(),greater<int>());
		sum2=2*8*0.95+func(book_list_copy);
		book_list_copy=book_list;
		for(vector<int>::iterator index=book_list_copy.begin();index!=book_list_copy.end()-4;++index)
			(*index)-=1;
		sort(book_list_copy.begin(),book_list_copy.end(),greater<int>());
		sum1=8+func(book_list_copy);
		return min(sum1,sum2,sum3,sum4,max_float);
	}
	else if(book_list_copy[2]>=1){
		book_list_copy=book_list;
		for(vector<int>::iterator index=book_list_copy.begin();index!=book_list_copy.end()-2;++index)
			(*index)-=1;
		sort(book_list_copy.begin(),book_list_copy.end(),greater<int>());
		sum3=3*8*0.9+func(book_list_copy);
		book_list_copy=book_list;
		for(vector<int>::iterator index=book_list_copy.begin();index!=book_list_copy.end()-3;++index)
			(*index)-=1;
		sort(book_list_copy.begin(),book_list_copy.end(),greater<int>());
		sum2=2*8*0.95+func(book_list_copy);
		book_list_copy=book_list;
		for(vector<int>::iterator index=book_list_copy.begin();index!=book_list_copy.end()-4;++index)
			(*index)-=1;
		sort(book_list_copy.begin(),book_list_copy.end(),greater<int>());
		sum1=8+func(book_list_copy);
		return min(sum1,sum2,sum3,max_float,max_float);
	}
	else if(book_list_copy[1]>=1){
		book_list_copy=book_list;
		for(vector<int>::iterator index=book_list_copy.begin();index!=book_list_copy.end()-3;++index)
			(*index)-=1;
		sort(book_list_copy.begin(),book_list_copy.end(),greater<int>());
		sum2=2*8*0.95+func(book_list_copy);
		book_list_copy=book_list;
		for(vector<int>::iterator index=book_list_copy.begin();index!=book_list_copy.end()-4;++index)
			(*index)-=1;
		sort(book_list_copy.begin(),book_list_copy.end(),greater<int>());
		sum1=8+func(book_list_copy);
		return min(sum1,sum2,max_float,max_float,max_float);
	}
	else if(book_list_copy[0]>=1){
		book_list_copy=book_list;
		for(vector<int>::iterator index=book_list_copy.begin();index!=book_list_copy.end()-4;++index)
			(*index)-=1;
		sort(book_list_copy.begin(),book_list_copy.end(),greater<int>());
		sum1=8+func(book_list_copy);
		return min(sum1,max_float,max_float,max_float,max_float);
	}
	else
		return 0;
}



int main(int argc,char** argv){
	vector<int> book_list;

	book_list.push_back(2);
	book_list.push_back(2);
	book_list.push_back(2);
	book_list.push_back(1);
	book_list.push_back(1);
	// �ź���
	sort(book_list.begin(),book_list.end(),greater<int>( ));
	float sum_least=func(book_list);
	cout<<"The least cost of the way to buy the book is :"<<sum_least<<endl;


}
//#include <iostream>
//#include <cstdlib>
//#include <cstdio>
//using namespace std;
//const int larg = 100000;//����һ�����ֵ���൱��ȡ��Сֵʱ�������λ�õ�ֵ
//
//template <typename T>
//void rerank(T  m[],int length)//ð������
// {            
//            for (int i = length-1; i >0; i--)
//            {
//                for (int j = 0; j < i; j++)
//                {
//                    if (m[j]>m[j +1])
//                    {
//                        T temp;
//                        temp = m[j + 1];
//                        m[j + 1] = m[j];
//                        m[j] = temp;
//                    }
//                }
//            }
// }
//
// double Min(double a, double b, double c, double d, double e)//������Сֵ
// {
//            double nn[5]={a,b,c,d,e};           
//            rerank(nn,5);
//            
//            return nn[0];
// }
//    
//double find_BestSol(int x1, int x2, int x3, int x4, int x5)//��̬�滮���ݹ�ʵ�֣�
//{
//            int n[5] ={ x1, x2, x3, x4, x5 };
//            rerank(n,5);//��n���д�С��������
//            x1 = n[0];
//            x2 = n[1];
//            x3 = n[2];
//            x4 = n[3];
//            x5 = n[4];
//            /* x1 < x2 < x3 < x4  < x5*/
//            if (n[0] > 0)//��С�Ķ�����0�������о���������0��Ȼ�����п����ۿ����г�����������Сֵ
//            {
//                return Min(8.0 + find_BestSol(x1, x2, x3, x4, x5 - 1),
//                                       2 * 8 * 0.95 + find_BestSol(x1, x2, x3, x4 - 1, x5 - 1),
//                                       3 * 8 * 0.9 + find_BestSol(x1, x2, x3 - 1, x4 - 1, x5 - 1),
//                                       4 * 8 * 0.8 + find_BestSol(x1, x2 - 1, x3 - 1, x4 - 1, x5 - 1),
//                                       5 * 8 * 0.75 + find_BestSol(x1 - 1, x2 - 1, x3 - 1, x4 - 1, x5 - 1));
//
//            }
//            else if ((n[0] == 0) && (n[1] > 0))
//            {
//                return Min(8.0 + find_BestSol(x1, x2, x3, x4, x5 - 1),
//                                    2 * 8 * 0.95 + find_BestSol(x1, x2, x3, x4 - 1, x5 - 1),
//                                    3 * 8 * 0.9 + find_BestSol(x1, x2, x3 - 1, x4 - 1, x5 - 1),
//                                    4 * 8 * 0.8 + find_BestSol(x1, x2 - 1, x3 - 1, x4 - 1, x5 - 1), larg);
//
//            }
//            else if ((n[0] == 0) && (n[1] == 0) && (n[2] > 0))
//            {
//                return Min(8.0 + find_BestSol(x1, x2, x3, x4, x5 - 1),
//                                    2 * 8 * 0.95 + find_BestSol(x1, x2, x3, x4 - 1, x5 - 1),
//                                    3 * 8 * 0.9 + find_BestSol(x1, x2, x3 - 1, x4 - 1, x5 - 1),
//                                    larg, larg);
//            }
//            else if ((n[0] == 0) && (n[1] == 0) && (n[2] == 0) && (n[3] > 0))
//            {
//                return Min(8.0 + find_BestSol(x1, x2, x3, x4, x5 - 1),
//                                    2 * 8 * 0.95 + find_BestSol(x1, x2, x3, x4 - 1, x5 - 1),
//                                    larg, larg, larg);
//            }
//            else if ((n[0] == 0) && (n[1] == 0) && (n[2] == 0) && (n[3] == 0) && (n[4] > 0))
//            {
//                return 8.0 + find_BestSol(x1, x2, x3, x4, x5 - 1);
//            }
//            else//��Ϊ0
//            {
//                return 0;
//            }
//        }
//  
//int  main()
//{
//       //int n1[5] = {3,4,2,1,0};
//       int n1[5] = {2,2,2,1,1};
//       double solution = find_BestSol(n1[0],n1[1],n1[2],n1[3],n1[4]);
//       cout<<"�����ѵ����ٵ�ǮΪ��"<<solution<<endl;  
//}

