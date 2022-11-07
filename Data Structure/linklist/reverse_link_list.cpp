// reverse link list
// Time Complexity: O(n) = O(Number of nodes present in the list)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int a) {
            num = a;
            next = NULL;
        }
};
//utility function to insert node at the end of the list
void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

//utility function to reverse link list
// Time Complexity: O(n) = O(Number of nodes present in the list)
// Space Complexity: O(1)
node* reverseList(node* head) {
    node* newHead = NULL;
    
    while(head != NULL){
        node* next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}

//utility function to print list
void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    } 
    cout<<head->num<<endl;
    return;
}

int main() {
    node* head = NULL;
    //inserting Node
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    
    cout<<"Original list: ";
    printList(head);
    
    node* newHead = reverseList(head);//calling function for reverse link list
    
    cout<<"After reverse: ";
    printList(newHead);
    return 0;
}