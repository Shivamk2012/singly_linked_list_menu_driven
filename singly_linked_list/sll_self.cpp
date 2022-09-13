#include<iostream>
#include<conio.h>
using namespace std;
class Node
{
public:
    int item;
    Node *next;
    Node(int d)
    {
        item=d;
        next=NULL;
    }
};
void insertAtFirst(Node* &head,Node* &tail,int d)
{
    Node *ptr=new Node(d);
    if(head==NULL){
        head=ptr;
        tail=ptr;
        return ;
    }
    ptr->next=head;
    head=ptr;
}
void insertAtLast(Node* &head,Node* &tail,int d){
    Node *ptr=new Node(d);
    if(head==NULL){
        head=ptr;
        tail=ptr;
        return ;
    }
    tail->next=ptr;
    tail=ptr;
}

void print(Node *head){
    if(head==NULL){
        cout<<"empty linked list"<<endl;
        return ;
    }
    while(head!=NULL){
        cout<<head->item<<" ";
        head=head->next;
    }
}

int getLength(Node *head){
    int l=0;
    while(head!=NULL){
        l++;
        head=head->next;
    }
    return l;
}

void insertAtPosition(Node* &head,Node* &tail,int d,int pos){
    Node *ptr=new Node(d);
    if(pos<1 || pos>getLength(head)+1){
        cout<<"invalid position"<<endl;
        return ;
    }
    if(pos==1){
        insertAtFirst(head,tail,d);
        return ;
    }
    int cnt=1;
    Node *temp=head;
    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtLast(head,tail,d);
        return ;
    }
    ptr->next=temp->next;
    temp->next=ptr;
}

void deleteNode(Node* &head,Node* &tail,int pos){
    if(pos<1 || pos>getLength(head)){
        cout<<"invalid position"<<endl;
        return ;
    }
    else if(pos==1)
    {
        Node *p=head;
        head=head->next;
        p->next=NULL;
        delete p;
        return ;
    }

    else{
        Node *t1=head;
        Node *t2=NULL;
        int cnt=1;
        while(cnt<pos){
            t2=t1;
            t1=t1->next;
            cnt++;
        }
        t2->next=t1->next;
        if(t1->next==NULL)
            tail=t2;
        t1->next=NULL;
        delete t1;
    }

}

int menu(){
    int c;
    cout<<"1.INSERT AT FIRST"<<endl;
    cout<<"2.INSERT AT LAST"<<endl;
    cout<<"3.INSERT AT MID"<<endl;
    cout<<"4.DELETE A NODE"<<endl;
    cout<<"5.EXIT"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>c;
    return c;
}
int main()
{
    int d,pos;
    Node *head=NULL;
    Node *tail=NULL;
    while(1){
        system("cls");
        cout<<"Nodes : ";
        print(head);
        cout<<endl<<"size :"<<getLength(head)<<endl;
        switch(menu())
        {
        case 1:
            cout<<"Enter a number to insert"<<endl;
            cin>>d;
            insertAtFirst(head,tail,d);
            break;
        case 2:
            cout<<"Enter a number to insert"<<endl;
            cin>>d;
            insertAtLast(head,tail,d);
            break;
        case 3:
            cout<<"Enter a number to insert"<<endl;
            cin>>d;
            cout<<"Enter position"<<endl;
            cin>>pos;
            insertAtPosition(head,tail,d,pos);
            break;
        case 4:
            cout<<"Enter node position to delete"<<endl;
            cin>>pos;
            deleteNode(head,tail,pos);
            break;
        case 5:
            exit(0);
            break;
        default:
            cout<<"invalid choice! Enter choice b/w 1-5"<<endl;
        }
        cout<<"Press Enter to continue"<<endl;
        getch();
    }
    return 0;
}

