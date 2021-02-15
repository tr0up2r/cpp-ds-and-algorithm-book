#include <array>
#include <iostream>
#include <type_traits>

// ���� ������ �Ű������� ����ϱ� ���� ���� ���ø� ���
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

	// ���� ��� ������ float��
	for (auto i : data)
		std::cout << i << " ";
	std::cout << '\n';

	return 0;
}