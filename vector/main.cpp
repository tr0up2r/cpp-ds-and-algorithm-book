#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> vec = { 1, 2, 3, 4, 5 };

	// ������ �� �տ� ���ο� ���� �߰�
	vec.insert(vec.begin(), 0);


	std::vector<int> vec2;	// ��� �ִ� ���� ���� : {}
	vec2.push_back(1);		// �� �ڿ� 1 �߰�
	vec2.push_back(2);		// �� �ڿ� 2 �߰�
	vec2.insert(vec2.begin(), 0);	// �� �տ� 0 �߰�
	vec2.insert(find(vec2.begin(), vec2.end(), 1), 4);	// 1 �տ� 4 �߰�

	vec2.emplace_back(3);	// �� �ڿ� 3 �߰� (����, �̵��� ��� ���� ����ȭ!)
	vec2.emplace(vec2.begin(), -1);	// �� �տ� -1 �߰� (�� ���� insert���� ����ȭ ����)

	for (auto i : vec2)
		std::cout << i << ' ';
	std::cout << '\n';


	std::vector<int> vec3 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// �� ������ ���� �ϳ� ����
	vec3.pop_back();

	// �� ó�� ���� ����
	vec3.erase(vec3.begin());

	// 1��° ���Һ��� 4��° �� ���ұ��� ����
	// ���� ��ġ ���Ҵ� ���ŵ����� �� ��ġ ���Ҵ� ���ŵ��� ����.
	vec3.erase(vec3.begin() + 1, vec3.begin() + 4);

	for (auto i : vec3)
		std::cout << i << ' ';

	vec3.clear();	// ��� ���� ����

	return 0;
}