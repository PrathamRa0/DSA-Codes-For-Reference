 #include<iostream>
 using namespace std;

class node{
    public:
        int data;
        node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertatTail(node* &head, int val) //head points to the address of the first node
{ //here we are taking head by reference and not by value as we need to change to value.
    node* n = new node(val);

    if(head==NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = n;
}

/*
void insertatHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
    head = n;
} */

void evenafterodd(node* &head)
{
    node* odd=head;
    node* even=head->next;
    node* evenStart = even;
    while(odd->next!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenStart;
    if(odd->next!=NULL)
        even->next=NULL;
}

void display(node* head) //here we are taking head by value and not by reference as we wont be changing the value.
{
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node* head=NULL;
    insertatTail(head,1);
    insertatTail(head,2);
    insertatTail(head,3);
    insertatTail(head,4);
    insertatTail(head,5);
    insertatTail(head,6);
    display(head);
    evenafterodd(head);
    display(head);
    return 0;
}