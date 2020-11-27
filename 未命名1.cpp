/*#include <iostream>
using namespace std;
 
#define N 100   //默认有99个物品。第一个不使用
int w[N];    //每个物品的重量
int v[N];    //每个物品的价值
int x[N];     //x[i]=1：物品i放入背包，0代表不放入
int n,c;       //n：一共有多少物品，c：背包的最大容量

int CurWeight = 0;  //当前放入背包的物品总重量
int CurValue = 0;   //当前放入背包的物品总价值

int BestValue = 0;  
int BestX[N];       
 
void input()
{
    cout<<"请输入物品的个数："<<endl;
    cin>>n;
    cout<<"请输入每个物品的重量及价值(如12 22):"<<endl;
    for(int i = 1; i <= n; i++)
    {
        cin>>w[i]>>v[i];
    }
    cout<<"请输入背包的容量："<<endl;
    cin>>c;
}
void output()
{
    cout<<"最优值是:"<<BestValue<<endl;
    cout<<"(";
    for(int i=1;i<=n;i++)
        cout<<BestX[i]<<" ";
    cout<<")";
 
}
//回溯函数 
void backtrack(int t)
{
    //叶子节点，输出结果
    if(t>n)
    {
        //如果找到了一个更优的解
        if(CurValue>BestValue)
        {
            //保存更优的值和解
            BestValue = CurValue;
            for(int i=1; i<=n; ++i)
                BestX[i] = x[i];
        }
    }
    else
    {
        //遍历当前节点的子节点：0 不放入背包，1放入背包
        for(int i=0; i<=1; ++i)
        {
            x[t]=i;
 
            if(i==0) //不放入背包
            {
                backtrack(t+1);
            }
            else //放入背包
            {
                //约束条件：放的下
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

	int Place(int t){//后面的BackTrack要用Place，所以要在BackTrack前定义Place 
		for(int i=1;i<t;i++)//i=1开始，BackTrack(1)从1开始 
		//因为x[t]是与t的前面比较，所以i<t，注意这里是x[t]与x[i]，主要是列号,所以行号i<t
		 {
			if((abs(x[t]-x[i])==abs(t-i))||(x[t]==x[i]))//这里的x[t]是BackTrack里进来的x[t]，所以在Place里x[t]算常量，而x[i]是变量 
			return 0;
			}//当x[t]与前面的x[i]都比较完，而且通过上面的if语句，才会跳出来返回return 1
			return 1;
	}
	
	void BackTrack(int t){
		if(t>n){//能走到t>n表明满足前面的所有条件，才到达终点，没有if或者while，即不需判断，下面{}里的语句都会执行
				count++;
				cout<<"Squeence is  "<<count<<"  , Array is  ";
			for(int i=1;i<=n;i++)//输出序列 ，从1开始  
				cout<<x[i]<<" ";
				cout<<endl; 
	}
		else{
			for(int i=1;i<=n;i++){//没到达终点，逐个遍历 
				x[t]=i;//x[]这里的t是由进来的BackTrack决定的，不受i影响，i只是给x[t]赋值
				if(Place(t)==1)//满足Place则进入下一层递归 ，这里的if没有分号，若有等于空语句，因为不管if，BackTrack(t+1)都执行。
				BackTrack(t+1);//BackTrack(t+1)设置在for里，这样可以对于x[t]=1,2,3,...n分别遍历它的BackTrack(t+1) 
			}
		}
	}
	
    int main(){
		count=0;
    	cout<<"How many queens?"<<endl;
    	cin>>n;
    	BackTrack(1);//从1开始遍历，注意不是从0 
   		return 0;
	}

