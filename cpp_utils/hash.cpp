#include <iostream>
#include <functional>
#include <string>

int main()
{
	int x;

	// char型の値'C'に対するハッシュ値を求める
	std::cout << std::hash<char>()('C') << std::endl;

	// int型の値100に対するハッシュ値を求める
	std::cout << std::hash<int>()(100) << std::endl;

	// double型の値3.14に対するハッシュ値を求める
	std::cout << std::hash<double>()(3.14) << std::endl;

	// int*型のアドレス値(&x)に対するハッシュ値を求める
	std::cout << std::hash<int *>()(&x) << std::endl;

	// stringは変数に入れないとだめ。直接渡すとchar[]と解釈される
	std::string msg = "hogehoge";
	auto hashed = std::hash<std::string>()(msg);
}