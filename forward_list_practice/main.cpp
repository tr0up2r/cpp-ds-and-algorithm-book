#include <string>
#include <iostream>
#include <forward_list>

struct  citizen
{
	std::string name;
	int age;
};

std::ostream& operator<<(std::ostream& os, const citizen& c)
{
	return (os << "[" << c.name << ", " << c.age << "]");
}

int main(void)
{
	std::forward_list<citizen> citizens = {
		{ "Kim", 22 }, { "Lee", 25 }, { "Park", 18 }, { "Jin", 16 }
	};

	auto citizens_copy = citizens;	// ���� ����

	std::cout << "��ü �ùε� : ";
	for (const auto& c : citizens)
		std::cout << c << ' ';
	std::cout << '\n';

	// age�� �̿��� ��ǥ���� ���� �ù��� ����Ʈ���� ����
	citizens.remove_if([](const citizen& c) {
		// ���̰� 19������ ������ ����Ʈ���� ����
		return (c.age < 19);
		});

	std::cout << "��ǥ���� �ִ� �ùε� : ";
	for (const auto& c : citizens)
		std::cout << c << " ";
	std::cout << '\n';

	citizens_copy.remove_if([](const citizen& c) {
		return (c.age != 18);
		});

	std::cout << "���⿡ ��ǥ���� ����� �ùε� : ";
	for (const auto& c : citizens_copy)
		std::cout << c << ' ';
	std::cout << '\n';

	return 0;
}