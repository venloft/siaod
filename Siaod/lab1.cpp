# include <iostream>
# include <conio.h>
# include <stdlib.h>
# include <time.h>
using namespace std;

//���� ���������
struct node
{
    int info; //�������������� ����
    node *l, *r;//����� � ������ ����� ������
};
 
node * tree=NULL; //��������� ����������, ��� ������� ��������� ������
 
/*������� ������ �������� � �������� ������*/
void push(int a,node **t)
{
    if ((*t)==NULL) //���� ������ �� ����������
    {
        (*t)=new node; //�������� ������
        (*t)->info=a; //������ � ���������� ����� �������� a
        (*t)->l=(*t)->r=NULL; //������� ������ ��� ���������� �����
        return; //�������� �������, �������
    }
       //������ ����
        if (a>(*t)->info)
		 push(a,&(*t)->r); //���� �������� � ������ ��� ������� �������, ������ ��� ������
        else push(a,&(*t)->l); //����� ������ ��� �����
}
 
/*������� ����������� ������ �� ������*/
void print (node *t,int u) 
{
    if (t==NULL) return; //���� ������ ������, �� ���������� ������, �������
    else //�����
    {
    print(t->l,++u);//� ������� ������������ �������� ����� ���������
    for (int i=0;i<u;++i) 
	cout<<"/";
    cout<<t->info<<endl; // ���������� �������
    u--;
    print(t->r,++u); //� ������� �������� �������� ������ ���������
	}
}
//������ ����
	void lr(struct node *t)
	{

	if(t==NULL)
	return;
	cout<<" "<<t->info; 
	lr(t->l);

	lr(t->r);

	}


//������
int height(struct node *t)
{
        struct node *temp=t;
        if(t==NULL)
		return(0);
		else
        return(max(height(t->l),height(t->r))+1);
}
//������
int razmer(struct node *t)
{
        struct node *temp=t;
        if(t==NULL)
		return(0);
  		else
        return(razmer(t->l)+razmer(t->r)+1);
}
//���� ������
int svd(struct node *t,int l)
{
        struct node *temp=t;
        if(t==NULL)
		return(0);
  		else
        return(l+svd(t->l,l+1)+svd(t->r,l+1));
}
// ����� ��������� ���� ������
int ks(struct node *t)
{
        struct node *temp=t;
        if(t==NULL)
		return(0);
  		else
        return(t->info+ks(t->l)+ks(t->r));
}
 
int main ()
{   
	 srand(time(NULL));
    int n; //���������� ���������
    int s=0; //�����, ������������ � ������
    cout<<"input  ";
    cin>>n; //������ ���������� ���������
 
    for (int i=0;i<n;++i)
    {
    s=rand()%10+1;
  //  s++;
    push(s,&tree); //� ������ ������ � ������
    }
    cout<<"\nOur tree\n";
    print(tree,0);
    cout<<"\nVisota = "<<height(tree)<<endl<<"Razmer = "<<razmer(tree)<<endl<<"Srednya visota = "<<svd(tree,1)/razmer(tree)<<endl<<"summa kontr = "<<ks(tree)<<endl;
 	lr(tree);
    getch();       
}
