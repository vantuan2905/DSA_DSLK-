#include<bits/stdc++.h>
using namespace std;
struct tree{
	char key;
	tree* l,*r;
};
tree* newnode(char x){
	tree* t=new tree();
	t->key=x;
	t->l=NULL;t->r=NULL;
	return t;
}
void lnr(tree* a){
	if(a==NULL) return;
	lnr(a->r);
	cout<<a->key<<"";
	lnr(a->l);
}
main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack<tree*> st;
		for(int i=0;i<s.length();i++){
			if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
				tree* a=st.top();st.pop();
				tree* b=st.top();st.pop();
				tree* t=newnode(s[i]);
				t->l=a;t->r=b;
				st.push(t);
			}else st.push(newnode(s[i]));
		}
		lnr(st.top());
		cout<<endl;
	}
}
