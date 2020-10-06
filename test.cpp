#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *rear,*head,*l4;
        int flag=0;

        head=new ListNode;
        head->next=NULL;
        rear=head;

        for(;l1!=NULL&&l2!=NULL;l1=l1->next,l2=l2->next)
        {
            l4=new ListNode;l4->next=NULL;
            l4->next=NULL;
            if(l1->val+l2->val+flag>9){
                l4->val=flag+l1->val+l2->val-10;flag=1;
                rear->next=l4;
            }
            else{
                l4->val=flag+l1->val+l2->val;flag=0;
                rear->next=l4;
            }
            rear=l4;
        }
        if(l1==NULL)
        {
            while(l2!=NULL)
            {
                l4=new ListNode;l4->next=NULL;
                if(l2->val+flag>9){
                    l4->val=flag+l2->val-10;flag=1;
                    rear->next=l4;
                }
                else{
                    l4->val=flag+l2->val;flag=0;
                    rear->next=l4;
                }
                rear=l4;
            }
        }
        else if(l2==NULL)
        {
            while(l1!=NULL)
            {
                l4=new ListNode;l4->next=NULL;
                if(l1->val+flag>9){
                    l4->val=flag+l1->val-10;flag=1;
                    rear->next=l4;
                }
                else{
                    l4->val=flag+l1->val;flag=0;
                    rear->next=l4;
                }
                rear=l4;
            }
        }
        if(flag==1){
            l4=new ListNode;
            l4->val=1;l4->next=NULL;
            rear->next=l4;
            rear=l4;
        }
        ListNode *ans=head->next;
        delete head;
        return ans;
    }
    

int main()
{
  

}