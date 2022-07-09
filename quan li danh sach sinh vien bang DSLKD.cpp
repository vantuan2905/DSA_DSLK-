#include<bits/stdc++.h>
using namespace std;
struct student{
	string ten,id;float gpa;
};
struct SV{
	student s;
	SV* next;
};
typedef struct SV* sv;
sv makenode(){
	sv t=new SV();student tmp;cin.ignore();
	cout<<"Nhap ho ten sinh vien: ";getline(cin,tmp.ten);
	cout<<"Nhap ma id sinh vien: ";cin>>tmp.id;
	cout<<"nhap diem sinh vien: ";cin>>tmp.gpa;
	t->s=tmp;
	t->next=NULL;
	return t;
}
int size(sv a){
	int cnt=0;
	while(a!=NULL){
		cnt++;//cout<<cnt<<endl;
		a=a->next;
	}
	return cnt;
}
void insertFirst(sv &a){
	sv tmp=makenode();
	if(a==NULL) a=tmp;
	else{
		tmp->next=a;a=tmp;
	}
}
void insertLast(sv &a){
	sv p=a;
	sv tmp=makenode();
	if(a==NULL) a=tmp;
	else{
		while(p->next!=NULL){p=p->next;
		}
		p->next=tmp;
	}
}
void insertMiddle(sv &a,int pos){
	int n=size(a);
	if(pos<=0||pos>n+1) return;
	if(pos==1) insertFirst(a);
	else{
		cout<<n<<endl;
		if(pos==n+1) insertLast(a);
		else{
			sv p=a;
			for(int i=1;i<pos-1;i++) p=p->next;
			sv t=makenode();
			t->next=p->next;
			p->next=t;
		}
	}
}
void deleteFirst(sv &a){
	a=a->next;
}
void deleteLast(sv &a){
	sv sau=a,truoc=NULL;
	if(size(a)==1){
		a=NULL;return;
	}
	while(sau->next!=NULL){
		truoc=sau;sau=sau->next;
	}
	truoc->next=NULL;
}
void deleteMiddle(sv &a,int pos){
	int n=size(a);
	if(pos<=0||pos>n) return;
	if(pos==1) deleteFirst(a);
	else{
		if(pos==n) deleteLast(a);
		else{
			sv truoc=NULL,sau=a;
			for(int i=1;i<pos;i++){truoc=sau; sau=sau->next;}
			truoc->next=sau->next;
			return;
		}
	}
}
void in(sv a){
	cout<<"---thong tin sinh vien---\n";
	while(a!=NULL){
		cout<<a->s.ten<<" "<<a->s.id<<" "<<fixed<<setprecision(2)<<a->s.gpa<<endl;a=a->next;
	}
	cout<<"---------------------------\n\n";
	return;
}
void sx(sv &a){
	for(sv p=a;p!=NULL;p=p->next){
		sv min=p;
		for(sv q=p;q!=NULL;q=q->next){
			if(q->s.gpa<min->s.gpa){
				min=q;
			}
		}
		student t=p->s;p->s=min->s;min->s=t;
	}
	return;
}
main(){
	sv head=NULL;
	while(1){
	cout<<"1.chen them sinh vien vao dau danh sach lien ket\n";
	cout<<"2.chen them sinh vien vao cuoi danh sach lien ket\n";
	cout<<"3.chen them sinh vien vao giua danh sach lien ket\n";
	cout<<"4.xoa them sinh vien vao dau danh sach lien ket\n";
	cout<<"5.xoa them sinh vien vao cuoi danh sach lien ket\n";
	cout<<"6.xoa them sinh vien vao giua danh sach lien ket\n";
	cout<<"7.sap xep theo gpa tang dan\n";
	cout<<"8.in ra \n";
	int n;
	cin>>n;
	if(n==1){
		insertFirst(head);
		cout<<size(head)<<endl;
	}
	if(n==2){
		insertLast(head);
	}
	if(n==3){int vt;cin>>vt;
		insertMiddle(head,vt);
	}
	if(n==4){
		deleteFirst(head);
	}
	if(n==5){
		deleteLast(head);
	}
	if(n==6){int vt;cin>>vt;
		deleteMiddle(head,vt);
	}
	if(n==7) sx(head);
	if(n==8) in(head);
}
}
