#include <iostream>
#include <forward_list>
#include <vector>

int main(void)
{
	// 최근 경기 우승자 명단을 작성
	std::vector<std::string> vec = {
		"Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg",
		"Sebastian Vettel", "Lewis Hamilton", "Sebastian Vettel",
		"Sebastian Vettel", "Sebastian Vettel", "Fernando Alonso"
	};

	auto it = vec.begin();
	std::cout << "가장 최근 우승자 : " << *it << '\n';

	it += 8;
	std::cout << "8년 전 우승자 : " << *it << '\n';

	// 반복자를 거리 값만큼 증가
	advance(it, -3);
	std::cout << "그 후 3년 뒤 우승자 : " << *it << '\n';


	std::forward_list<std::string> fwd(vec.begin(), vec.end());

	auto it1 = fwd.begin();
	std::cout << "가장 최근 우승자 : " << *it1 << '\n';

	advance(it1, 5);
	std::cout << "5년 전 우승자 : " << *it1 << '\n';

	// 순방향 이동만 가능하기 때문에 advance(it1, -2); 는 에러 발생.

	return 0;
}