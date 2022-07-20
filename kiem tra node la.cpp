#include<bits/stdc++.h>
using namespace std;
struct node{
	int d;
	node* l,*r;
};	int m=0;
node* create(int x){
	node* t=new node();
	t->d=x;
	t->r=t->l=NULL;
	return t;
}
void them(node* t,int b,char c){
	if(t==NULL) return;
	if(c=='L') t->l=create(b);
	else t->r=create(b);
}
void them(node* &t,int a,int b,int c){
	if(t==NULL) return;
	if(t->d==a){
		them(t,b,c);return;
	}
	them(t->l,a,b,c);them(t->r,a,b,c);
}
void ql(node* h,int lv){
	if(h==NULL||m==-1) return;
	if(h->l==NULL&&h->r==h->l){
		if(m==0) m=lv;
		else{
			if(lv!=m) m=-1;
		}
	}else{
		ql(h->l,lv+1);ql(h->r,lv+1);
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
		int n;node* h=NULL;
		cin>>n;
		for(int i=0;i<n;i++){
			int a,b;char c;
			cin>>a>>b>>c;
			if(h==NULL){
				h=create(a);
			}
			them(h,a,b,c);
		}
		m=0;
		ql(h,0);
		if(m==-1) cout<<0<<endl;
		else cout<<1<<endl;
	}
}
