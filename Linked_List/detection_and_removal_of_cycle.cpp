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
    cout<<"NULL"<<endl;
}

bool detectCycle(node* &head)
{
    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}

void makeCycle(node* &head, int pos)
{
    node* temp = head;
    node* startNode;

    int count = 1;
    while(temp->next!=NULL)
    {
        if(count==pos)
        {
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next = startNode;

}

void removeCycle(node* &head)
{
    node* fast=head;
    node* slow=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);

    // Slow and fast pointer will be at the same pos.
    fast = head;
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next = NULL;

}

int main()   //FLOYD'S ALGORITHM 
{
    node* head=NULL;
    insertatTail(head, 1);
    insertatTail(head, 2);
    insertatTail(head, 3);
    insertatTail(head, 4);
    insertatTail(head, 5);
    insertatTail(head, 6);
    makeCycle(head,3);
    //display(head);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    display(head);
    return 0;
}