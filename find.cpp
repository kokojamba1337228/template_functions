#include <iostream>
#include<vector>

namespace mylib {
	template<class Iterator, class T>
	Iterator find(Iterator first, Iterator last, T value) {
		for (; first != last; ++first)
		{
			if (*first == value) {
				return first;
			}
		}
		return last;
	}
}




int main()
{

	std::vector<int> arr{ 1, 2, 3, 4, 5 };
	std::vector<int>::iterator result = mylib::find(arr.begin(), arr.end(), 2);
	if (result == arr.end()) {
		std::cout << "wtf" << std::endl;
	}
	else {
		//std::cout << result << std::endl;
		std::cout << (*result) << std::endl;
		*result = 10;
	}
	std::cout << arr[1] << std::endl;
}
