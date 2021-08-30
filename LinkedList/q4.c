#include <stdlib.h>
#include <stdbool.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

Node *reverse(Node *head)
{
    Node *previousNode = NULL;
    while (head)
    {
        Node *temp = head->next;
        head->next = previousNode;
        previousNode = head;
        head = temp;
    }
    return previousNode;
}

bool isPalindrome(struct ListNode *head)
{
    Node *slow = (Node *)malloc(sizeof(Node));
    Node *fast = (Node *)malloc(sizeof(Node));
    fast->next = head;
    slow->next = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = slow->next;

    Node *reversedSecondHalf = reverse(slow);
    slow = head;
    while (reversedSecondHalf)
    {
        if (reversedSecondHalf->val != slow->val)
            return 0;
        reversedSecondHalf = reversedSecondHalf->next;
        slow = slow->next;
    }
    return 1;
}
