#include <iostream>
#include <forward_list>
#include <vector>

int main(void)
{
	// �ֱ� ��� ����� ����� �ۼ�
	std::vector<std::string> vec = {
		"Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg",
		"Sebastian Vettel", "Lewis Hamilton", "Sebastian Vettel",
		"Sebastian Vettel", "Sebastian Vettel", "Fernando Alonso"
	};

	auto it = vec.begin();
	std::cout << "���� �ֱ� ����� : " << *it << '\n';

	it += 8;
	std::cout << "8�� �� ����� : " << *it << '\n';

	// �ݺ��ڸ� �Ÿ� ����ŭ ����
	advance(it, -3);
	std::cout << "�� �� 3�� �� ����� : " << *it << '\n';


	std::forward_list<std::string> fwd(vec.begin(), vec.end());

	auto it1 = fwd.begin();
	std::cout << "���� �ֱ� ����� : " << *it1 << '\n';

	advance(it1, 5);
	std::cout << "5�� �� ����� : " << *it1 << '\n';

	// ������ �̵��� �����ϱ� ������ advance(it1, -2); �� ���� �߻�.

	return 0;
}