/*
 * 翻转链表 指定位置   前面翻转  后面翻转
 * 123456   3     321654      5    543216
 * 要求：
 * 思路：始终记录前一个结点和后一个结点以及头结点，然后遍历的过程中就执行翻转，然后达到指定地点后，对后面执行同样的翻转，只不过需要记录的是最后一个结点
 * 问题：空指针，链表长度问题等等
 * */

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode
{
	int data;
	struct LinkNode *next;
}LinkNode, *LinkList;

/* 构造函数 */
LinkList createLinkList(void);
/* 遍历链表 */
int traverseLinkList(LinkList head);
/* 翻转两个结点 */
int reverseTwoNode(LinkNode *pre, LinkNode *curr);
/* 翻转指定的一段链表 */
LinkList reverseLinkList(LinkList beg, int len);


int main(void)
{
	int i = 0;
	LinkList head, pwork, firhead, tail, sechead;
	head = pwork = NULL;
//	for (i = 0; i < 10; i++)
//	{
	head = createLinkList();
		//printf("%d\n", head->data);//不能直接这么用，需要显示初始化？
//	}
    pwork = head->next;
    traverseLinkList(pwork);
    firhead = reverseLinkList(pwork, 6);
    printf("第一轮翻转结束.\n");
    traverseLinkList(firhead);
    if(pwork->next != NULL)
    {
        //printf("pwork->next:%d, nextnext:%d\n", pwork->next->data, pwork->next->next->data);
        sechead = reverseLinkList(pwork->next, -1);
        pwork->next = sechead; 
        printf("第二轮翻转结束.\n");
        traverseLinkList(firhead); 
    }
    //pwork->next = sechead; 
    //traverseLinkList(firhead); 
    
/*
    pwork = head->next;   
	while (pwork)
	{
		printf("%d-", pwork->data);
		pwork = pwork->next;
	}	
*/
	return 0;
}

/* 头插法 */
LinkList createLinkList(void)
{
	int data = 0;
	LinkList head, tail;
	head = (LinkList)malloc(sizeof(struct LinkNode));
	tail = head;
    tail->next = NULL;
    printf("请输入数据，每次输入一个，输入-1结束\n");
    scanf("%d", &data);
    while(data != -1)
    {
	    LinkNode *node = (LinkNode *)malloc(sizeof(struct LinkNode));
	    node->data = data;
	    node->next = NULL;
	    tail->next = node;
        tail = node;
        scanf("%d", &data);
    }
/*
	if (head == NULL)
	{
		printf("test\n");
		head = (LinkList)malloc(sizeof(struct LinkNode));
		head->data = data;
		head->next = NULL;
		printf("%d\n", head->data);
		
		return 0;
	}
*/
	return head;
}

int traverseLinkList(LinkList head)
{
    LinkList pwork = head;
    while(pwork)
    {
        printf("%d ", pwork->data);
        pwork = pwork->next;
    }
    printf("\n");
    return 0;
}

int reverseTwoNode(LinkNode *pre, LinkNode *curr)
{
    /*
    if(pre != NULL)
    {
        pre->next = NULL;
    }
    */
    if(curr != NULL)
    {
        curr->next = pre;    
    }
    return 0;
}

/* 返回新链表的头部 */
LinkList reverseLinkList(LinkList beg, int len)
{
    int count = 1, temp = len;
    LinkList phead, ppre, pcurr, pnext;
    phead = ppre = pcurr = pnext = NULL;
    phead =  ppre = beg;
    //printf("beg:%d, pcurr:%d\n", beg->data, pcurr->data);
    /* 不用翻转 输入长度或者实际长度小于2  */
    if (len == 0 || len == 1 || ppre == NULL)
        return phead;
    pcurr = ppre->next;
    if (pcurr == NULL)
        return phead;
    //printf("ppre:%d, pcurr:%d\n", ppre->data, pcurr->data);
    pnext = pcurr->next;
    /* 先自断后路，方便对下面的结点统一处理 */
    beg->next = NULL;

    //printf("pcurr:%d\n", pcurr->data); 
    while (pcurr)
    {
        //count++;
        reverseTwoNode(ppre, pcurr);
        count++;
        if(temp == -1)
            len = count+1;
        if(pnext == NULL || count == len)
        {
            //停止翻转
            phead = pcurr;
            break;
        }
        ppre = pcurr;
        pcurr = pnext;
        pnext = pnext->next;
    }
    beg->next = pnext; 
    return phead;
}
