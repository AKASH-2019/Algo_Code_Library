#include<bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // using mege sort approch
        // tc: O(n1+n2)
        // sc: O(n1+n2)
        ListNode* dummy = new ListNode;
        ListNode* cur = dummy;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        if(list1->val < list2->val){
            cur->next = list1;
            list1 = list1->next;
        }else{
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
        
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                cur->next = list1;
                list1 = list1->next;
            }else{
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        
        if(list1 != NULL){
            cur->next = list1;
        }
        if(list2 != NULL){
            cur->next = list2;
        }
        return dummy->next;
        /*
        // brute force..
        // tc: O(n1+n2)
        // sc: O(n1+n2)
        ListNode* dummy = new ListNode;
        ListNode* cur = dummy;
        
        while(1){
            if(list1 == NULL && list2 == NULL){
                break;
            }
            else if(list1 == NULL && list2 != NULL){
                cur->next = list2;
                list2 = list2->next;
            }
            else if(list1 != NULL && list2 == NULL){
                cur->next = list1;
                list1 = list1->next;
            }
            else if(list1->val < list2->val){
                cur->next = list1;
                list1 = list1->next;
            }
            else if(list1->val >= list2->val){
                cur->next = list2;
                list2 = list2->next;
            }
            
            cur = cur->next;
        }
        
        return dummy->next;
        */
    }
};