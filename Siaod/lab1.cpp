# include <iostream>
# include <conio.h>
# include <stdlib.h>
# include <time.h>
using namespace std;

//Наша структура
struct node
{
    int info; //Информационное поле
    node *l, *r;//Левая и Правая часть дерева
};
 
node * tree=NULL; //Объявляем переменную, тип которой структура Дерево
 
/*ФУНКЦИЯ ЗАПИСИ ЭЛЕМЕНТА В БИНАРНОЕ ДЕРЕВО*/
void push(int a,node **t)
{
    if ((*t)==NULL) //Если дерева не существует
    {
        (*t)=new node; //Выделяем память
        (*t)->info=a; //Кладем в выделенное место аргумент a
        (*t)->l=(*t)->r=NULL; //Очищаем память для следующего роста
        return; //Заложили семечко, выходим
    }
       //Дерево есть
        if (a>(*t)->info)
		 push(a,&(*t)->r); //Если аргумент а больше чем текущий элемент, кладем его вправо
        else push(a,&(*t)->l); //Иначе кладем его влево
}
 
/*ФУНКЦИЯ ОТОБРАЖЕНИЯ ДЕРЕВА НА ЭКРАНЕ*/
void print (node *t,int u) 
{
    if (t==NULL) return; //Если дерево пустое, то отображать нечего, выходим
    else //Иначе
    {
    print(t->l,++u);//С помощью рекурсивного посещаем левое поддерево
    for (int i=0;i<u;++i) 
	cout<<"/";
    cout<<t->info<<endl; // показываем элемент
    u--;
    print(t->r,++u); //С помощью рекурсии посещаем правое поддерево
	}
}
//сверху вниз
	void lr(struct node *t)
	{

	if(t==NULL)
	return;
	cout<<" "<<t->info; 
	lr(t->l);

	lr(t->r);

	}


//высота
int height(struct node *t)
{
        struct node *temp=t;
        if(t==NULL)
		return(0);
		else
        return(max(height(t->l),height(t->r))+1);
}
//размер
int razmer(struct node *t)
{
        struct node *temp=t;
        if(t==NULL)
		return(0);
  		else
        return(razmer(t->l)+razmer(t->r)+1);
}
//сред высота
int svd(struct node *t,int l)
{
        struct node *temp=t;
        if(t==NULL)
		return(0);
  		else
        return(l+svd(t->l,l+1)+svd(t->r,l+1));
}
// сумма элементов всех вершин
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
    int n; //Количество элементов
    int s=0; //Число, передаваемое в дерево
    cout<<"input  ";
    cin>>n; //Вводим количество элементов
 
    for (int i=0;i<n;++i)
    {
    s=rand()%10+1;
  //  s++;
    push(s,&tree); //И каждый кладем в дерево
    }
    cout<<"\nOur tree\n";
    print(tree,0);
    cout<<"\nVisota = "<<height(tree)<<endl<<"Razmer = "<<razmer(tree)<<endl<<"Srednya visota = "<<svd(tree,1)/razmer(tree)<<endl<<"summa kontr = "<<ks(tree)<<endl;
 	lr(tree);
    getch();       
}
