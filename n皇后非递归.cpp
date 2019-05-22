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


int check(int p,int j){
		
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
				return 1;
			}else{
				return 0;
			}
} 
void  dfs(int p){
	//cout<<p<<endl;
	int j=0;
	while(p!=-1){
		
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
			
			p--;
			for(int h=0;h<n;h++){
					if(a[p][h]==1){
						j=h+1;
						a[p][h]=0;
						break;
					}
			}
			continue;
		}
		
		if(check(p,j)==1){
			cout<<p<<" "<<j<<"\n";
			a[p][j]=1;
			p++;
			j=0;
				
		}else{
			cout<<p<<" "<<j<<"\n";
			if(j==n-1){
				p--;
				if(p==-1){
					break ;
				}
				for(int h=0;h<n;h++){
					if(a[p][h]==1){
						j=h+1;
						a[p][h]=0;
						if(j==n){
							p--;
							for(int h=0;h<n;h++){
								
							}
						}
						break;
					}
				}
				
			}else{
				j++;
			}	
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
