#include <iostream>
#include <forward_list>

int main(void)
{
	std::forward_list<int> fwd_list = { 1, 2, 3 };

	fwd_list.push_front(0);	// �� �տ� 0 �߰�
	
	auto it = fwd_list.begin();
	fwd_list.insert_after(it, 5);	// �� ó�� ���� �ڿ� 5 �߰�
	fwd_list.insert_after(it, 6);	// ���� ��ġ�� 6 �߰�

	// std::vector�� emplace�� ���� ����, ȿ����
	fwd_list.emplace_front(10);
	fwd_list.emplace_after(it, 20);

	for (auto i : fwd_list)
		std::cout << i << ' ';
	std::cout << '\n';
	


	std::forward_list<int> fwd_list2 = { 1, 2, 3, 4, 5 };

	fwd_list2.pop_front();	// �� �� ���Ҹ� ����

	auto it2 = fwd_list2.begin();
	fwd_list2.erase_after(it2);	// �� ���� ���� ���Ҹ� ����
	fwd_list2.erase_after(it2, fwd_list2.end());	// �� �� ���� �������� �� ������ ���ұ��� ����

	for (auto i : fwd_list2)
		std::cout << i << ' ';

	return 0;
}