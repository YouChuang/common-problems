/*
 * 链表数据结构，带头结点的链表
 * Sort a linked list using insertion sort.
 * */
#include <stdio.h>
#include <stdlib.h>

/* 基本结构体 */
/* 单链表 */
typedef struct LinkNode 
{
    int value;
    struct LinkNode *next;
}LinkNode, *LinkList;

/* 基本函数 */
/* 构造函数 */
LinkList createLinkList(void);
/* 遍历 */
int traverseLinkList(LinkList head);
/* 特定位置插入特定数据 */
int insertLinkList(LinkList head, int address, int data );
/* 各种排序 */
int sortList(LinkList list);


int main(void)
{
    int i = 0, address = 0, data = 0;
    LinkList head;
    head = createLinkList();
    traverseLinkList(head);
    printf("分别输入插入的位置和插入的数据\n");
    scanf("%d", &address);
    scanf("%d", &data);
    insertLinkList(head, address, data);
    traverseLinkList(head);
    return 0;
}


/* 构造函数 头结点 尾插法 元素个数自定义或者不限 */
LinkList createLinkList(void)
{
   /*
    ListNode node = (ListNode)malloc(sizeof(struct ListNode));
    node.value = value;
    node.next = list;
    list = (&node);
    */
    char *strdata, arraydata[100], ch;
    int i = 0, num = 0, data = 0, tmpdata = 0;
    LinkList head = (LinkList)malloc(sizeof(struct LinkNode));
    LinkList tail = head;
    tail->next = NULL;
    //printf();
    /* 固定元素个数的构造 */
/*  scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%d", &data);
        LinkNode *node = (LinkNode*)malloc(sizeof(struct LinkNode));
        node->value = data;
        node->next = NULL;
        tail->next = node;
        tail = node;
    }
*/
    /* 不固定个数的构造 输入-1结束，如果想同时输入多个数据呢？空格分割 用字符数组 */
    //scanf("%s", strdata);
    while (1)
    {
        scanf("%d", &tmpdata);
        printf("input:%d\n", tmpdata);
        ch = getchar();
        if (ch == '\n')
            break;
    }
    //for ()
    /* 别忘了清空缓冲区 */
    while(((ch = getchar()) != '\n') && (ch != EOF));
    scanf("%d", &data);
    while (data != -1)
    {
        LinkNode *node = (LinkNode*)malloc(sizeof(struct LinkNode));
        node->value = data;
        node->next = NULL;
        tail->next = node;
        tail = node;
        scanf("%d", &data);
    }  
    /*
    ListNode *node = (ListNode *)malloc(sizeof(struct ListNode));
    node->value = value;//与(*node).value同义
    node->next = list;
    list = node;
    */
    return head;
}

int traverseLinkList(LinkList head)
{
    LinkNode *pwork = head->next; 
    while(pwork != NULL)
    {
        printf("value = %d\n", pwork->value);
        pwork = pwork->next;
    }
    return 0;
    
}

int insertLinkList(LinkList head, int address, int data)
{
    int i = 1;
    LinkNode *ppre = head;
    LinkNode *pwork = ppre->next;
    LinkNode *node = (LinkNode*)malloc(sizeof(struct LinkNode)); 
    node->value = data;
    node->next = NULL;
    while(i < address && pwork != NULL)
    {
        i++;
        ppre = pwork;
        pwork = pwork->next;
    }
    if(pwork==NULL)
    {
        ppre->next = node;
    }
    else
    {
        ppre->next = node;
        node->next = pwork;
    }
    return 0;
}

/*
LinkList insertLinkList(LinkList head, int data )
{
    
}
*/
