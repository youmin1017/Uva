#include <iostream>
#include <string>
//the decoder

int main()
{
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::string input;

	while(std::getline(std::cin, input))
	{
		for(char& x : input)
			std::cout << static_cast<char>(x-7);
		
		std::cout << std::endl;
	}
	
	return 0;
}