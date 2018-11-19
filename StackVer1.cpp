#include<stdio.h>
#include<conio.h>
struct Node // Tao node
{
	int Data;
	Node *Next;
};
struct Stack 
{
	Node *Top;
};
void Init (Stack &s) // tao stack
{
	s.Top=NULL;
}
int Isempty(Stack s) // kiem tra stack rong 
{
	return (s.Top == NULL);
}
int Len (Stack s)
{
	Node *P=s.Top;
	int i=0;
	while(P!=NULL)
	{
		i++;
		P=P->Next;
	}
	return i;
}
Node* GetNode(int x) // tao 1 node
{
	Node *p = new Node;
	if(p!=NULL)
	{
		p->Data=x;
		p->Next=NULL;
	} 
	return p;
}
void Push(Stack &s, int x) // them 1 phan tu
{
	Node *p = GetNode(x);
	p->Next = s.Top;
	s.Top=p;
}
int Peak(Stack S) // lay phan tu dau nhung khong xoa
{
	return S.Top->Data;
}
int Pop(Stack &S) // xoa mot phan tu dau
{
	if (!Isempty(S))
	{
		int x = S.Top->Data;
		S.Top=S.Top->Next;
		return x;
	}
}
void Input(Stack &s) // nhap danh sach
{
	int i=0;
	int x;
	do
	{
		i++;
		printf("Nhap phan tu thu %d : ",i);
		scanf("%d",&x);
		if(x != 0)
		Push(s,x);
	} while(x != 0);
}
void Output(Stack S) // xuat 
{
	Node *p = S.Top;
	while (p != NULL)
	{
		printf("%d ",p->Data);
		p=p->Next;
	}
	printf("\n");
}

int main()

{
	Stack S;
    Init(S);
    Input(S);
    Output(S);
    int lua_chon;
    printf("Moi ban chon phep toan voi DS LKD:");
    printf("\n1: Kiem tra Stack rong");
    printf("\n2: Do dai Stack");
    printf("\n3: Them phan tu vao Stack");
    printf("\n4: Xoa phan tu trong Stack");
    printf("\n5: Xuat Stack");
    printf("\n6: Thoat");
       do
    {
        printf("\nBan chon: ");
        scanf("%d",&lua_chon);
        switch (lua_chon)
        {
            case 1:
            {
                if (Isempty(S)) printf("Stack rong !");
                else printf ("Stack khong rong !");
                break;
            }
            case 2:
            {
                printf("Do dai Stack: %d",Len(S));
                break;
            }
            case 3:
            {
                int x;
                printf ("Nhap phan tu can chen vao DS: ");
                scanf("%d",&x);
                Push(S,x);
                break;
            }
            case 4:
            {
                Pop(S);
                break;
            }
            case 5: 
            {
                Output(S);
                break;
            }
            case 6: break;
        }
    }while (lua_chon !=6);
    return 0;
}

