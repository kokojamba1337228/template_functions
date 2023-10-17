#include <iostream>
#include<vector>

namespace ml {
	template<class Iterator, class T>
	T acumulate(Iterator first, Iterator last, T result) {
		for (; first != last; ++first)
		{
			result += *first;
		}
		return result;
	}

	template<class Iterator, class T, class BinaryOperation>
	T acumulate(Iterator first, Iterator last, T result, BinaryOperation bp) {
		for (; first != last; ++first)
		{
			result = bp(result, *first);
		}
		return result;
	}
	template<class Iterator, class T>
	T avg(Iterator first, Iterator last, T result) {
		T sum = acumulate(first, last, result);
		int size = last - first;
		return sum / size;
	}
	template<class Iterator>
	void series_4(Iterator first, Iterator last) {
		std::cout << ml::acumulate(first, last, 0, [](int a, int b) {return a + b; }) << std::endl;
		std::cout << ml::acumulate(first, last, 1, [](int a, int b) {return a * b; }) << std::endl;
	}
	template<class Iterator, class UnaryOperation>
	void for_each(Iterator first, Iterator last, UnaryOperation up) {
		for (; first != last; ++first)
		{
			up(*first);
		}
	}
}

int main()
{
	int arr[]{ 1, 2, 3 ,4 ,5 ,6 ,7 };
	std::vector<int> vec{ 1, 2, 3 ,4 ,5 ,6 ,7 };
	std::cout << ml::acumulate(arr, arr + 7, 0, [](int a, int b) 
		{return a + b; }) << std::endl;
	std::cout << ml::acumulate(vec.begin(), vec.end(), 1, [](int a, int b) 
		{return a * b; }) << std::endl;
	int sum = 0;
	double sum1 = 0;
	std::cout << ml::avg(vec.begin(), vec.end(), 0) << std::endl;
	ml::for_each(arr, arr + 7, [&sum, &sum1](double value)
		{std::cout << static_cast<int>(value) << " ";
		std::cout << value - static_cast<int>(value) << " ";
		sum += value;
		sum1 += value - static_cast<int>(value); });
	std::cout << std::endl;
	ml::for_each(arr, arr + 7, [](int& value)
		{value = std::round(value);
		std::cout << value; });
	sum = 0;
	std::cout << std::endl;
	ml::for_each(arr, arr + 7, [&sum](int value)
		{if (value % 2 == 0) {
		std::cout << value << " ";
	}; });
}
