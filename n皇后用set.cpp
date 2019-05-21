#include<iostream>
#include<stdio.h>
#include<vector>
#include<stdio.h>
#include<set> 
using namespace std;
int n;
int cnt=0;
int cnt2=0;
int a[50][50];
set<int> col;
set<int> pie;
set<int> na;
vector<vector<string> > v2;

void  dfs(int p){
	//cout<<p<<endl;
	if(p==n){
		//cout<<"2\n";
		cnt++;
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
	
	//int flag=0;
	for(int j=0;j<n;j++){  
		
		
		if(col.count(j)==0&&pie.count(p+j)==0&&na.count(p-j)==0){
			//flag=1;
			col.insert(j);pie.insert(p+j);na.insert(p-j);
			a[p][j]=1;
			dfs(p+1);
			cnt2++;
			col.erase(j);pie.erase(p+j);na.erase(p-j);
			a[p][j]=0;
		}	
	}
	return ;
}
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	dfs(0); 
	cout<<cnt<<" "<<cnt2<<endl;
	return 0;
} 
