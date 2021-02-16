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

	fwd_list.push_front(0);	// 맨 앞에 0 추가
	
	auto it = fwd_list.begin();
	fwd_list.insert_after(it, 5);	// 맨 처음 원소 뒤에 5 추가
	fwd_list.insert_after(it, 6);	// 같은 위치에 6 추가

	// std::vector의 emplace와 같은 동작, 효율적
	fwd_list.emplace_front(10);
	fwd_list.emplace_after(it, 20);

	print(fwd_list);
	


	std::forward_list<int> fwd_list2 = { 1, 2, 3, 4, 5 };

	fwd_list2.pop_front();	// 맨 앞 원소를 삭제

	auto it2 = fwd_list2.begin();
	fwd_list2.erase_after(it2);	// 맨 앞의 다음 원소를 삭제
	fwd_list2.erase_after(it2, fwd_list2.end());	// 맨 앞 원소 다음부터 맨 마지막 원소까지 삭제

	print(fwd_list2);



	std::forward_list<int> list1 = { 23, 0, 1, -3, 34, 32 };
	list1.sort();

	// 표준으로 제공되는 비교 함수 객체
	// 원소를 내림차순으로 정렬하기 위한 > 연산자에 대한 래퍼
	list1.sort(std::greater<int>());

	print(list1);



	std::forward_list<int> list2 = { 2, 53, 1, 0, 4, 10 };
	list2.reverse();
	print(list2);

	list2 = { 0, 1, 0, 1, -1, 10, 5, 5, 10, 0 };
	list2.unique();
	print(list2);

	// 정렬 후 unique를 하면 유일한 원소들만 남음
	list2 = { 0, 1, 0, 1, -1, 10, 5, 5, 10, 0 };
	list2.sort();
	list2.unique();
	print(list2);

	// 리스트에서 특정 원소가 바로 앞 원소보다 2 이상 크지 않으면 삭제
	list2.unique([](int a, int b) { return (b - a) < 2; });
	print(list2);

	return 0;
}