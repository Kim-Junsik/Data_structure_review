void split(ListNode** A, ListNode** B, ListNode* C) {
	ListNode* p = C;
	bool flag = true;
	while (p != NULL) {
		if (flag) {
			insert_node_back(A, create_node(p->data));
			p = p->link;
			flag = false;
		}
		else {
			insert_node_back(B, create_node(p->data));
			p = p->link;
			flag = true;
		}
	}
	return;
}