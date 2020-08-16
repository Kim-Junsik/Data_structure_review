typedef struct element {
	int row;
	int col;
	int value;
};
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;