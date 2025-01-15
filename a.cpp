#include <iostream>
#include <vector> 
using namespace std;
struct Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;

    }

    public:
    Node (int data1){
        data=data1;
        next=nullptr;

    }


};
Node* convertarrtoLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
    
}
int lengthofLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while (temp)
    {
        temp=temp->next;
        cnt++;
    }
    return cnt;
    
}

int main() {
    vector<int> arr;
    arr.push_back(11); 
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    Node* head=convertarrtoLL(arr);
    Node* temp=head;
    cout<<"This is the linked list -> ";

    while (temp)
    {
        cout<< temp->data <<" ";
        temp=temp->next;

    }
    cout<<endl;

    cout<<"Length of the LL -> "<<lengthofLL(head);


    
  
}