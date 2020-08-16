int poly_eval(ListHeader* plist, int x) {
	int sum = 0;
	ListNode* a = plist->head;
	while (a) {
		int temp = 1;
		for (int i = 0; i < a->expon; i++)
			temp *= x;
		sum += temp * a->coef;
		a = a->link;
	}
	return sum;
}