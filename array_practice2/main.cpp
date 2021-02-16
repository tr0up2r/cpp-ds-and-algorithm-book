#include <array>
#include <iostream>
#include <type_traits>

// 임의 개수의 매개변수를 허용하기 위해 가변 템플릿 사용
template<typename ... Args>
auto build_array(Args&&... args)->std::array<typename std::common_type
	<Args...>::type, sizeof...(args)>
{
	using commonType = typename std::common_type<Args...>::type;
	return { std::forward<commonType>((Args&&)args)... };
}

int main()
{
	auto data = build_array(1, 0u, 'a', 3.2f, false);

	// 최종 출력 형식은 float형
	for (auto i : data)
		std::cout << i << " ";
		
	std::cout << '\n';

	return 0;
}