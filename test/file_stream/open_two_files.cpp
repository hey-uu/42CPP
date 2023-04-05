#include <iostream>
#include <fstream>
#include <string>

int	main(void)
{
	std::ifstream in("test.txt");
	std::string s;

	if (in.is_open()) {
		in >> s;
		std::cout << "입력 받은 문자열 :: " << s << std::endl;
	} else {
		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
	}
	in.close(); 
	in.open("other.txt");
	// 같은 객체로 새로운 파일을 다시 열려면 
	// close를 통해 기존 파일 스트림과의 연결을 종료한 후에
	// 새로운 파일과 연결시켜줘야함
	if (in.is_open()) {
		in >> s;
		std::cout << "입력 받은 문자열 :: " << s << std::endl;
	} else {
		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
	}
	return (0);
}