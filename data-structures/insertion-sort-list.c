/*
 * Sort a linked list using insertion sort.
 * */
#include <stdio.h>
#include <stdlib.h>

/* 基本结构体 */
typedef struct ListNode 
{
    int value;
    struct ListNode *next;
}ListNode, *LinkList;

/* 基本函数 */
LinkList createList(LinkList list, int value);
int sortList(LinkList list);

/* 构造函数 */
LinkList createList(LinkList list, int value)
{
    ListNode *node = (ListNode *)malloc(sizeof(struct ListNode));
    node->value = value;
    node->next = list;
    list = node;
    return list;
}



int main(void)
{
    int i = 0;
    LinkList head = (LinkList)malloc(sizeof(struct ListNode));
    head->value = 0;
    head->next = NULL;
    for (i = 10; i > 0; i--)
        head = createList(head, i);
    while(head != NULL)
    {
        printf("value = %d\n", head->value);
        head = head->next;
    }
    return 0;
}
