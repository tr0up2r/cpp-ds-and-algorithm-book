#include <iostream>
#include <array>

// std::array �迭�� ������ �����ϴ� print() �Լ�
void print(std::array<int, 5> arr)	// �ڵ����� ���� ����. ���ο� �迭�� ��� ���� ����
{
	// range-based for�� �̿��� �ݺ� ���(�ݺ��ڷ� ���� ����)
	for (auto ele : arr)
		std::cout << ele << ' ';
}


// ������ ����� ���� �Լ� ���ø� ����
template <size_t N>
void print2(const std::array<int, N>& arr)
{
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		auto element = (*it);
		std::cout << element << ' ';
	}
}

int main(void)
{
	// arr1
	std::array<int, 10> arr1;

	arr1[0] = 1;
	std::cout << "arr1 �迭�� ù��° ���� : " << arr1[0] << '\n';


	// arr2
	std::array<int, 4> arr2 = { 1, 2, 3, 4 };
	std::cout << "arr2�� ��� ���� : ";

	for (int i = 0; i < arr2.size(); i++)
		std::cout << arr2[i] << ' ';
	std::cout << '\n';


	// arr3
	std::array<int, 4> arr3 = { 1, 2, 3, 4 };

	try
	{
		std::cout << arr3.at(3) << '\n';	// ���� �ƴ�
		std::cout << arr3.at(4) << '\n';	// std::out_of_range ���� �߻�
	}
	catch (const std::out_of_range& ex)
	{
		std::cerr << ex.what() << '\n';
	}


	// print �Լ� �̿�
	std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
	print(arr);


	// ���� ���� �Լ� ���
	std::array<int, 5> arr4 = { 1, 2, 3, 4, 5 };
	std::cout << arr4.front() << '\n';
	std::cout << arr4.back() << '\n';
	std::cout << *(arr4.data() + 1) << '\n';

	return 0;
}