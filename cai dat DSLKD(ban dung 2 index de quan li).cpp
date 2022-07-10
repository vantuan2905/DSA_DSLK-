#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct data{
	int n;
};
struct node{
	data dt;
	node* next;
};
struct listt{
	node* pHead;node* pTail;
};
void init(listt &l){l.pTail=NULL;
	l.pHead=NULL;
}
node* makenode(int x){
	node* p=new node();
	p->dt.n=x;
	p->next=NULL;
	return p;
}
int size(listt l){
	node* p=l.pHead;int cnt=0;
	while(p!=NULL){
		cnt++;p=p->next;
	}
	return cnt;
}
void insertFirst(listt &l,int x){
	node* p=l.pHead,* t=makenode(x);
	if(p==NULL) l.pHead=l.pTail=t;
	else{
		t->next=p;
		l.pHead=t;
}
}
void insertLast(listt &l,int x){
	if(l.pHead==NULL) insertFirst(l,x);
	else{
		node* p=makenode(x);
		l.pTail->next=p;
		l.pTail=p;
	}
}
void insertMiddle(listt &l,int x,int pos){
	int s=size(l);
	if(pos<=0||pos>s+1) return;
	if(pos==1) insertFirst(l,x);else
	if(pos==s+1) insertLast(l,x);
	else{
		node* p=l.pHead;
		for(int i=1;i<pos-1;i++){
			p=p->next;
		}
		node* t=makenode(x);
		t->next=p->next;
		p->next=t;
	}
}
void deleteFirst(listt &l){
	if(l.pHead==l.pTail) l.pHead=l.pTail=NULL;
	else{
		l.pHead=l.pHead->next;
	}
}
void deleteLast(listt &l){
	if(l.pHead==l.pTail) l.pHead=l.pTail=NULL;
	else{
		node* sau=l.pHead,*truoc=NULL;
		while(sau->next!=NULL){
			truoc=sau;
			sau=sau->next;
		}
		truoc->next=NULL;
		l.pTail=truoc;
	}
}
void deleteMiddle(listt &l,int pos){
	int s=size(l);
	if(pos<=0||pos>s) return;
	if(pos==1) deleteFirst(l);else
	if(pos==s) deleteLast(l);else{
		node* truoc=NULL,* sau=l.pHead;
		for(int i=1;i<pos;i++){
			truoc=sau;sau=sau->next;
		}
		truoc->next=sau->next;
	}
}
void in(listt l){
	for(node* p=l.pHead;p!=NULL;p=p->next){
		cout<<p->dt.n<<" ";
	}
	cout<<endl;
}

main(){
	listt l;
	init(l);
	while(1){
		cout<<size(l)<<endl;
		cout<<"1.them vao dau\n";
		cout<<"2.them vao cuoi\n";
		cout<<"3.them vao giua\n";
		cout<<"4.xoa vao dau\n";
		cout<<"5.xoa vao giua\n";
		cout<<"6.xoa vao cuoi\n";
		cout<<"7.in\n";
		int lc;
		cin>>lc;
		if(lc==1){
			int x;
			cin>>x;
			insertFirst(l,x);
		}
		if(lc==2){
			int x;
			cin>>x;
			insertLast(l,x);
		}
		if(lc==3){
			int x,vt;
			cin>>x>>vt;
			insertMiddle(l,x,vt);
		}
		if(lc==4){
			deleteFirst(l);
		}
		
		if(lc==5){int vt;
		cin>>vt;
			deleteMiddle(l,vt);
		}
		if(lc==6){
			deleteLast(l);
		}
		if(lc==7){
			in(l);
		}
	}
}
