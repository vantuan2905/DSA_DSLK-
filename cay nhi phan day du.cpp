#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
	int d;
	node* l,*r;
};
node* createnode(int x){
	node* t=new node();
	t->d=x;
	t->l=t->r=NULL;
	return t;
}
void chen(node* &t,int b,char c){
	if(t==NULL) return;
	if(c=='L') t->l=createnode(b);
	else t->r=createnode(b);
}
void tao(node* &t,int a,int b,char c){ 
	if(t==NULL) return;
	if(t->d==a){
		chen(t,b,c);return;
	}
	tao(t->l,a,b,c);
	tao(t->r,a,b,c);
}
void kt(node *t,int &ans){
	if(t==NULL||ans==0) return ;
	if(t->l==NULL&&t->r==NULL) return;
	if(t->l==NULL||t->r==NULL){
		//cout<<t->d<<" toi day\n";
		ans=0;return;
	}
	kt(t->l,ans);
	kt(t->r,ans);
}
void in(node* h){
	if(h==NULL) return;
	cout<<h->d<<"  ";
	in(h->l);
	in(h->r);
}
main(){
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n;node *head=NULL;
		for(int i=0;i<n;i++){
			int a,b;char c;
			cin>>a>>b>>c;c=toupper(c);
			if(head==NULL){
				head=createnode(a);
			}
			tao(head,a,b,c);
		}
	//	in(head);
		//cout<<endl;
		int ans=1;
		kt(head,ans);
		cout<<ans<<endl;
	}
}
