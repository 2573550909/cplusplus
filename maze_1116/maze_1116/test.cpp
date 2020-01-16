#include <iostream>
#include <stdlib.h>
using namespace std;

class ListNode {
public:
	int x;
	ListNode* next;
};

ListNode* rotateRight(ListNode* head, int k) {
	if (head == nullptr || k == 0){
		return head;
	}
	int count = 0;
	ListNode* temp_count = head;
	//����������
	while (temp_count != nullptr) {
		count += 1;
		temp_count = temp_count->next;
	}
	//���k�������ȵı����򲻷�ת
	if (k%count == 0) {
		return head;
	}
	//# �ҵ��ô��ĸ�λ�öϿ�����
	int num = k % count;
	ListNode* cut = head;
	ListNode* temp = cut;
	int n = count - num;
	// 1->2->3->4->5->NULL, k = 2
	while (n > 1) {
		cut = cut->next;
		n -= 1;
	}
	ListNode* ret = cut->next;
	cut->next = nullptr;
	
	//# ���µ������ǽ� ret �������β��ƴ�ӵ�cut�ײ�
	ListNode* retlist = ret;
	while (ret->next != nullptr) {
		ret = ret->next;
	}
	ret->next = temp;
	return retlist;
}


int main() {
	ListNode* n1 = new ListNode;
	ListNode* n2 = new ListNode;
	ListNode* n3 = new ListNode;
	ListNode* n4 = new ListNode;
	ListNode* n5 = new ListNode;
	n1->x = 1; n2->x = 2; n3->x = 3;
	n4->x = 4; n5->x = 5;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = nullptr;

	ListNode* ret= rotateRight(n1,2);
	while (ret != nullptr) {
		printf("%d ", ret->x);
		ret = ret->next;
	}

	delete n1;
	delete n2;
	delete n3;
	delete n4;
	delete n5;

	system("pause");
	return 0;
}
