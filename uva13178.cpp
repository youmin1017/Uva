#include <iostream>

int main()
{
	int nums, n;

	std::cin >> nums;

	while(nums--)
	{
		std::cin >> n;

		std::cout << ( (n%3 == 1) ?  "NO" : "YES" ) << std::endl;

	}

	return 0;
}