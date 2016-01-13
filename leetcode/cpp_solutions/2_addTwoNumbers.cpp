#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *p1 = l1;
		ListNode *p2 = l2;

		ListNode *current = NULL;
		
		if (l1==NULL&&l2==NULL)
		{
			return NULL;
		}
		if (l1 == NULL&&l2 != NULL)
		{
			return l2;
		}
		if (l1 != NULL&&l2 == NULL)
		{
			return l1;
		}

		int flag = 0;
		while (p1 != NULL && p2 != NULL)
		{
			int tmp = p1->val + p2->val + flag;
			flag = tmp / 10;
			ListNode *node = new ListNode(tmp % 10);
			node->next = current;
			current = node;

			p1 = p1->next;
			p2 = p2->next;
		}

		if (p1 !=NULL && p2 == NULL)
		{
			while (p1 != NULL)
			{
				int tmp = p1->val + flag;
				flag = tmp / 10;
				ListNode *node = new ListNode(tmp % 10);
				node->next = current;
				current = node;
				p1 = p1->next;
			}
		}

		if (p2 != NULL && p1 == NULL)
		{
			while (p2 != NULL)
			{
				int tmp = p2->val + flag;
				flag = tmp / 10;
				ListNode *node = new ListNode(tmp % 10);
				node->next = current;
				current = node;
				p2 = p2->next;
			}
		}

		if (flag)
		{
			ListNode *node = new ListNode(flag);
			node->next = current;
			current = node;
		}

		ListNode* current_next = current->next;
		current->next = NULL;
		while (current_next != NULL)
		{
			ListNode *tmp = current_next->next;
			current_next->next = current;
			current = current_next;
			current_next = tmp;
		}

		return current;
	}
};

int main()
{
	Solution *s = new Solution();
	ListNode *a = new ListNode(2);
	a->next = new ListNode(4);
	//a->next->next = new ListNode(3);

	ListNode *b = new ListNode(9);
	//b->next = new ListNode(6);
	//b->next->next = new ListNode(4);
	ListNode *c = s->addTwoNumbers(a, b);
	return 0;
}
