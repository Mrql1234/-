#include<iostream>
#include<stdio.h>
#include<vector>
#include<stdio.h>
#include<set> 
using namespace std;
int n;
//int cnt=0;
//int cnt2=0;
int a[50][50];

vector<vector<string> > v2;

void  dfs(int p,int col,int pie,int na){ //int数据 0表示能放  1表示不能放 
	//cout<<p<<endl;
	if(p==n){
		//cout<<"2\n";
		//cnt++;
		vector<string> v1;
		for(int i=0;i<n;i++){
			
			string s;
			for(int j=0;j<n;j++){
				cout<<a[i][j]<<" ";
				if(a[i][j]!=1) s+=".";
				else s+="Q";
			}
			//cout<<s;
			cout<<"\n";	
			v1.push_back(s);	
		}
		cout<<"\n";
		v2.push_back(v1);
		return ;
	}
     	
	int bits = (~(col|pie|na))&((1<<n)-1); //把当前行的 列撇捺 与 再取反 & 后n位为1其余位为0  11 1010 & 00 1111 = 00 1010 
 	        							//得到当前行能 放皇后的位置 1表示能放   
	while(bits>0){
		int g= bits&(-bits);     //得到最右边1的数  00 1010 & 11 0110 = 00 0010 
		int x=1,y=g;          //得到具体位置的数字 放置皇后 
		//cout<<y<<endl;
		while(y>1){
			y=y>>1;
			x++;
		}
		//cout<<x;
		a[p][x-1]=1;   
		dfs(p+1,col|g,(pie|g)<<1,(na|g)>>1);//列 & g 撇 & g左移 捺 & g右移 
		a[p][x-1]=0;
		bits&=bits-1; //把当前放过的位置 置0 其他位不变 
		
	}
	return ;
}
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	dfs(0,0,0,0);  
	//cout<<cnt<<" "<<cnt2<<endl;
	return 0;
} 
