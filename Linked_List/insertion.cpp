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

void insertatHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
    head = n;
}

void display(node* head) //here we are taking head by value and not by reference as we wont be changing the value.
{
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    node* head=NULL;
    while(true)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            int val;
            cin>>val;
            insertatTail(head,val);
            display(head);
        }
        else if(n==2)
        {
            int val;
            cin>>val;
            insertatHead(head,val);
            display(head);
        }
        else{
            break;
        }
        
    }
    return 0;
}