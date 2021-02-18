#include <iostream>
#include <deque>

int main(void)
{
	std::deque<int> deq = { 1, 2, 3, 4, 5 };
	
	deq.push_front(0);	// �� �տ� 0 �߰�
	deq.push_back(6);	// �� �ڿ� 6 �߰�

	deq.insert(deq.begin() + 2, 10);	// �� �տ��� 2ĭ �ڿ� 10 �߰�

	deq.pop_back();		// �� �� ���� ����
	deq.pop_front();	// �� �� ���� ����

	deq.erase(deq.begin() + 1);
	deq.erase(deq.begin() + 3, deq.end());	// �տ��� 3��° ���Һ��� ������ ����

	for (auto i : deq)
		std::cout << i << ' ';
	std::cout << '\n';

	return 0;
}