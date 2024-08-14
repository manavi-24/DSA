/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void createcopy(Node*head){
        Node*temp=head;
        while(temp!=NULL){
            Node*store=temp->next;
            Node*newnode=new Node(temp->val);
            temp->next=newnode;
            newnode->next=store;
            temp=store;
        }
    }
    void connectrandom(Node*head){
        Node*temp=head;
        while(temp!=NULL){
            Node*copy=temp->next;
            if(temp->random){
                copy->random=temp->random->next;

            }
            else{
                copy->random=nullptr;
            }
            temp=temp->next->next;
        }
    }
    Node*getcopy(Node*head){
        Node*temp=head;
        Node*dummy=new Node(-1);
        Node*box=dummy;
        while(temp!=NULL){
            box->next=temp->next;
            box=box->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
        createcopy(head);
        connectrandom(head);
        return getcopy(head);
        
    }
};