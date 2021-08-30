#include <stdlib.h>
#include <stdbool.h>

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

struct ListNode *detectCycle(struct ListNode *head)
{
    if (!head || !head->next)
        return NULL;

    Node *fast = head->next;
    Node *slow = head;

    while (fast && fast->next && slow != fast)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (!fast || !fast->next)
        return NULL;

    fast = fast->next;
    slow = head;

  

    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
