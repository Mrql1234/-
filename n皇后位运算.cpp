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

void  dfs(int p,int col,int pie,int na){ //int���� 0��ʾ�ܷ�  1��ʾ���ܷ� 
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
     	
	int bits = (~(col|pie|na))&((1<<n)-1); //�ѵ�ǰ�е� ��Ʋ�� �� ��ȡ�� & ��nλΪ1����λΪ0  11 1010 & 00 1111 = 00 1010 
 	        							//�õ���ǰ���� �Żʺ��λ�� 1��ʾ�ܷ�   
	while(bits>0){
		int g= bits&(-bits);     //�õ����ұ�1����  00 1010 & 11 0110 = 00 0010 
		int x=1,y=g;          //�õ�����λ�õ����� ���ûʺ� 
		//cout<<y<<endl;
		while(y>1){
			y=y>>1;
			x++;
		}
		//cout<<x;
		a[p][x-1]=1;   
		dfs(p+1,col|g,(pie|g)<<1,(na|g)>>1);//�� & g Ʋ & g���� �� & g���� 
		a[p][x-1]=0;
		bits&=bits-1; //�ѵ�ǰ�Ź���λ�� ��0 ����λ���� 
		
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
