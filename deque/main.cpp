#include <iostream>
#include <deque>

int main(void)
{
	std::deque<int> deq = { 1, 2, 3, 4, 5 };
	
	deq.push_front(0);	// 맨 앞에 0 추가
	deq.push_back(6);	// 맨 뒤에 6 추가

	deq.insert(deq.begin() + 2, 10);	// 맨 앞에서 2칸 뒤에 10 추가

	deq.pop_back();		// 맨 뒤 원소 삭제
	deq.pop_front();	// 맨 앞 원소 삭제

	deq.erase(deq.begin() + 1);
	deq.erase(deq.begin() + 3, deq.end());	// 앞에서 3번째 원소부터 끝까지 삭제

	for (auto i : deq)
		std::cout << i << ' ';
	std::cout << '\n';

	return 0;
}