/*#include <iostream>
using namespace std;
 
#define N 100   //Ĭ����99����Ʒ����һ����ʹ��
int w[N];    //ÿ����Ʒ������
int v[N];    //ÿ����Ʒ�ļ�ֵ
int x[N];     //x[i]=1����Ʒi���뱳����0��������
int n,c;       //n��һ���ж�����Ʒ��c���������������

int CurWeight = 0;  //��ǰ���뱳������Ʒ������
int CurValue = 0;   //��ǰ���뱳������Ʒ�ܼ�ֵ

int BestValue = 0;  
int BestX[N];       
 
void input()
{
    cout<<"��������Ʒ�ĸ�����"<<endl;
    cin>>n;
    cout<<"������ÿ����Ʒ����������ֵ(��12 22):"<<endl;
    for(int i = 1; i <= n; i++)
    {
        cin>>w[i]>>v[i];
    }
    cout<<"�����뱳����������"<<endl;
    cin>>c;
}
void output()
{
    cout<<"����ֵ��:"<<BestValue<<endl;
    cout<<"(";
    for(int i=1;i<=n;i++)
        cout<<BestX[i]<<" ";
    cout<<")";
 
}
//���ݺ��� 
void backtrack(int t)
{
    //Ҷ�ӽڵ㣬������
    if(t>n)
    {
        //����ҵ���һ�����ŵĽ�
        if(CurValue>BestValue)
        {
            //������ŵ�ֵ�ͽ�
            BestValue = CurValue;
            for(int i=1; i<=n; ++i)
                BestX[i] = x[i];
        }
    }
    else
    {
        //������ǰ�ڵ���ӽڵ㣺0 �����뱳����1���뱳��
        for(int i=0; i<=1; ++i)
        {
            x[t]=i;
 
            if(i==0) //�����뱳��
            {
                backtrack(t+1);
            }
            else //���뱳��
            {
                //Լ���������ŵ���
                if((CurWeight+w[t])<=c)
                {
                    CurWeight += w[t];
                    CurValue += v[t];
                    backtrack(t+1);
                    CurWeight -= w[t];
                    CurValue -= v[t];
                }
            }
        }
    }
 
 
}
 
int main(int argc, char* argv[])
{
 
    input();
    backtrack(1);
    output();
    return 0;
}
#include<vector>
#include<string>
class Solution
{
public:
 Solution() {};
 ~Solution() {};
 std::vector<std::vector<std::string>> solveNQueens(int n)
 {
  std::vector<std::vector<std::string>> result;
  std::vector<std::vector<int>> mark;
  std::vector<std::string> location;
  for (int i = 0; i < n; i++)
  {
   mark.push_back((std::vector<int>()));
   for (int j = 0; j < n; j++)
   {
    mark[i].push_back(0);
   }
   location.push_back("");
   location[i].append(n,'.');
  }
  generate(0,n,location,mark,result);
  return result;
 }
private:
 void put_down_the_queen(int x, int y, std::vector<std::vector<int>>& mark)
 {
  static const int dx[] = { -1,1,0,0,-1,-1,1,1 };
  static const int dy[] = { 0,0,-1,1,-1,1,-1,1 };
  mark[x][y] = 1;
  for (unsigned int i = 1; i < mark.size(); i++)
  {
   for (int j = 0; j < 8; j++)
   {
    int new_x = x + i * dx[j];
    int new_y = y + i * dy[j];
    if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size())
    {
     mark[new_x][new_y] = 1;
    }
   }
  }
 }
 void generate(int k, int n, std::vector<std::string>& location, std::vector<std::vector<int>> &mark,  std::vector<std::vector<std::string>> &result)
 {
  if (k==n)
  {
   result.push_back(location);
   return;
  }
  for (int i = 0; i < n; i++)
  {
   if (mark[k][i]==0)
   {
    std::vector<std::vector<int>> tmp_mark=mark;
    location[k][i] = 'Q';
    put_down_the_queen(k, i, mark);
    generate(k + 1, n, location, mark, result);
    mark = tmp_mark;
    location[k][i] = '.';
   }
  }
 }
};
int main()
{
 std::vector<std::vector<std::string>> result;
 Solution solve;
 result = solve.solveNQueens(4);
 for (unsigned int i = 0; i < result.size(); i++)
 {
  printf("i=%d\n",i);
  for (int j = 0; j < result[i].size(); j++)
  {
   printf("%s\n",result[i][j].c_str());
  }
  printf("\n");
 }
 return 0;
}*/
#include <iostream>
#include<math.h>
using namespace std;
int x[100];
int count;
int n;

	int Place(int t){//�����BackTrackҪ��Place������Ҫ��BackTrackǰ����Place 
		for(int i=1;i<t;i++)//i=1��ʼ��BackTrack(1)��1��ʼ 
		//��Ϊx[t]����t��ǰ��Ƚϣ�����i<t��ע��������x[t]��x[i]����Ҫ���к�,�����к�i<t
		 {
			if((abs(x[t]-x[i])==abs(t-i))||(x[t]==x[i]))//�����x[t]��BackTrack�������x[t]��������Place��x[t]�㳣������x[i]�Ǳ��� 
			return 0;
			}//��x[t]��ǰ���x[i]���Ƚ��꣬����ͨ�������if��䣬�Ż�����������return 1
			return 1;
	}
	
	void BackTrack(int t){
		if(t>n){//���ߵ�t>n��������ǰ��������������ŵ����յ㣬û��if����while���������жϣ�����{}�����䶼��ִ��
				count++;
				cout<<"Squeence is  "<<count<<"  , Array is  ";
			for(int i=1;i<=n;i++)//������� ����1��ʼ  
				cout<<x[i]<<" ";
				cout<<endl; 
	}
		else{
			for(int i=1;i<=n;i++){//û�����յ㣬������� 
				x[t]=i;//x[]�����t���ɽ�����BackTrack�����ģ�����iӰ�죬iֻ�Ǹ�x[t]��ֵ
				if(Place(t)==1)//����Place�������һ��ݹ� �������ifû�зֺţ����е��ڿ���䣬��Ϊ����if��BackTrack(t+1)��ִ�С�
				BackTrack(t+1);//BackTrack(t+1)������for��������Զ���x[t]=1,2,3,...n�ֱ��������BackTrack(t+1) 
			}
		}
	}
	
    int main(){
		count=0;
    	cout<<"How many queens?"<<endl;
    	cin>>n;
    	BackTrack(1);//��1��ʼ������ע�ⲻ�Ǵ�0 
   		return 0;
	}

