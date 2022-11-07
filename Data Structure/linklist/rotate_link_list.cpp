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
//utility function to rotate list by k times brute force
// Time Complexity: O(Number of nodes present in the list*k) = n*k
// Space Complexity: O(1)
/*
node* rotateRight(node* head, int k){
    // edge case
    if(head == NULL || head->next == NULL || k == 0){
        return head;
    }
    for(int i=0; i<k; i++){
        node* temp = head;
        while(temp->next->next != NULL) temp = temp->next; // 1 2next, 2 3next, 3 4next, 4 5next, 5 NULL
        node* end = temp->next;    // temp->next =  4next
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}
*/
//utility function to rotate list by k times effecient approch
// Time Complexity: O(length of list) + O(length of list – (length of list%k)) == O(n) + O(n-k) = O(n)
// Space Complexity: O(1)
node* rotateRight(node* head, int k){
    // edge case
    if(head == NULL || head->next == NULL || k == 0){
        return head;
    }
    int ln=1;
    node* temp = head;
    while(temp->next != NULL){
        ln++;
        temp = temp->next;
    }
    temp->next = head;   // link the 1st node with last node (circular list)
    int k = k%ln;
    int shift = ln-k;
    
    while(shift--){
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    
    
    return head;
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
    
    int k = 3;
    node* newHead = rotateRight(head,k);//calling function for rotating right of the nodes by k times
    
    cout<<"After "<<k<<" iterations: ";
    printList(newHead);//list after rotating nodes
    return 0;
}