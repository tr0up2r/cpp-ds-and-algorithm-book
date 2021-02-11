#include <iostream>
#include <array>

// std::array 배열을 값으로 전달하는 print() 함수
void print(std::array<int, 5> arr)	// 자동으로 깊은 복사. 새로운 배열에 모든 원소 복사
{
	// range-based for를 이용한 반복 출력(반복자로 인해 가능)
	for (auto ele : arr)
		std::cout << ele << ' ';
}


// 범용적 사용을 위한 함수 템플릿 선언
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
	std::cout << "arr1 배열의 첫번째 원소 : " << arr1[0] << '\n';


	// arr2
	std::array<int, 4> arr2 = { 1, 2, 3, 4 };
	std::cout << "arr2의 모든 원소 : ";

	for (int i = 0; i < arr2.size(); i++)
		std::cout << arr2[i] << ' ';
	std::cout << '\n';


	// arr3
	std::array<int, 4> arr3 = { 1, 2, 3, 4 };

	try
	{
		std::cout << arr3.at(3) << '\n';	// 에러 아님
		std::cout << arr3.at(4) << '\n';	// std::out_of_range 예외 발생
	}
	catch (const std::out_of_range& ex)
	{
		std::cerr << ex.what() << '\n';
	}


	// print 함수 이용
	std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
	print(arr);


	// 원소 접근 함수 사용
	std::array<int, 5> arr4 = { 1, 2, 3, 4, 5 };
	std::cout << arr4.front() << '\n';
	std::cout << arr4.back() << '\n';
	std::cout << *(arr4.data() + 1) << '\n';

	return 0;
}