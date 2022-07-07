#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* next;
};
typedef Node* node;
node makenode(int x){
	node t=new Node();
	t->data=x;
	t->next=NULL;
	return t;
}
int size(node a){
	int cnt=0;
	while(a!=NULL){
		cnt++;
		a=a->next;
	}
	return cnt;
}
void back(node &a,int x){
	node tmp=makenode(x);
	if(a==NULL) a=tmp;
	else{
		node p=a;
		while(p->next!=NULL) p=p->next;
		p->next=tmp;
		return;
	}
}
void del(node &a,int vt){
	node truoc=NULL,sau=a;
	int n=size(a);
	if(vt==0||vt>n) return;
	for(int i=1;i<vt;i++){
		truoc=sau;sau=sau->next;
	}
	if(truoc==NULL) a=NULL;
	truoc->next=sau->next;return;
}
main(){
	int n,x;node head=NULL,tmp;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(head==NULL) head=makenode(a);
		else{
			back(head,a);
	}
	}
	cin>>x;
	tmp=head;head=NULL;
	for(int i=1;i<=n;i++){
		if(tmp->data!=x){ back(head,tmp->data);}
		tmp=tmp->next;
	}
	
	for(head;head!=NULL;head=head->next){
		cout<<head->data<<" ";
	}
	cout<<endl;
}

