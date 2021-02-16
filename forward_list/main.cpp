#include <iostream>
#include <forward_list>

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

	for (auto i : fwd_list)
		std::cout << i << ' ';
	std::cout << '\n';
	


	std::forward_list<int> fwd_list2 = { 1, 2, 3, 4, 5 };

	fwd_list2.pop_front();	// 맨 앞 원소를 삭제

	auto it2 = fwd_list2.begin();
	fwd_list2.erase_after(it2);	// 맨 앞의 다음 원소를 삭제
	fwd_list2.erase_after(it2, fwd_list2.end());	// 맨 앞 원소 다음부터 맨 마지막 원소까지 삭제

	for (auto i : fwd_list2)
		std::cout << i << ' ';

	return 0;
}