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
	
	
	for(int j=0;j<n;j++){  
		int x=p+j;
		int y=p-j;
		int flag=1;
		for(int q=0;q<p;q++){
			for(int h=0;h<n;h++){
				//cout<<j<<" "<<h<<endl;
				if(a[q][h]==1){
					if(h!=j&&x!=q+h&&y!=q-h){
						
					}else{
						flag=0; 
					}
					break;
				}
			}
		} 
		//cout<<"1"<<endl; 
		if(flag==1){
			a[p][j]=1;
			dfs(p+1);
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
