#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> vec = { 1, 2, 3, 4, 5 };

	// 벡터의 맨 앞에 새로운 원소 추가
	vec.insert(vec.begin(), 0);


	std::vector<int> vec2;	// 비어 있는 벡터 생성 : {}
	vec2.push_back(1);		// 맨 뒤에 1 추가
	vec2.push_back(2);		// 맨 뒤에 2 추가
	vec2.insert(vec2.begin(), 0);	// 맨 앞에 0 추가
	vec2.insert(find(vec2.begin(), vec2.end(), 1), 4);	// 1 앞에 4 추가

	vec2.emplace_back(3);	// 맨 뒤에 3 추가 (복사, 이동이 없어서 성능 최적화!)
	vec2.emplace(vec2.begin(), -1);	// 맨 앞에 -1 추가 (이 역시 insert보다 최적화 가능)

	for (auto i : vec2)
		std::cout << i << ' ';
	std::cout << '\n';


	std::vector<int> vec3 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// 맨 마지막 원소 하나 제거
	vec3.pop_back();

	// 맨 처음 원소 제거
	vec3.erase(vec3.begin());

	// 1번째 원소부터 4번째 앞 원소까지 제거
	// 시작 위치 원소는 제거되지만 끝 위치 원소는 제거되지 않음.
	vec3.erase(vec3.begin() + 1, vec3.begin() + 4);

	for (auto i : vec3)
		std::cout << i << ' ';

	vec3.clear();	// 모든 원소 제거

	return 0;
}