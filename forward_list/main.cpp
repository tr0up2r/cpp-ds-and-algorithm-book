#include <iostream>
#include <forward_list>

void print(const std::forward_list<int>& fl)
{
	for (auto i : fl)
		std::cout << i << ' ';
	std::cout << '\n';
}

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

	print(fwd_list);
	


	std::forward_list<int> fwd_list2 = { 1, 2, 3, 4, 5 };

	fwd_list2.pop_front();	// �� �� ���Ҹ� ����

	auto it2 = fwd_list2.begin();
	fwd_list2.erase_after(it2);	// �� ���� ���� ���Ҹ� ����
	fwd_list2.erase_after(it2, fwd_list2.end());	// �� �� ���� �������� �� ������ ���ұ��� ����

	print(fwd_list2);



	std::forward_list<int> list1 = { 23, 0, 1, -3, 34, 32 };
	list1.sort();

	// ǥ������ �����Ǵ� �� �Լ� ��ü
	// ���Ҹ� ������������ �����ϱ� ���� > �����ڿ� ���� ����
	list1.sort(std::greater<int>());

	print(list1);



	std::forward_list<int> list2 = { 2, 53, 1, 0, 4, 10 };
	list2.reverse();
	print(list2);

	list2 = { 0, 1, 0, 1, -1, 10, 5, 5, 10, 0 };
	list2.unique();
	print(list2);

	// ���� �� unique�� �ϸ� ������ ���ҵ鸸 ����
	list2 = { 0, 1, 0, 1, -1, 10, 5, 5, 10, 0 };
	list2.sort();
	list2.unique();
	print(list2);

	// ����Ʈ���� Ư�� ���Ұ� �ٷ� �� ���Һ��� 2 �̻� ũ�� ������ ����
	list2.unique([](int a, int b) { return (b - a) < 2; });
	print(list2);

	return 0;
}