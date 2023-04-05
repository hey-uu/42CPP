#include <fstream>
#include <iostream>
#include <string>

int main(void)
{
	// 생성자에 파일 경로를 지정하면 해당 파일을 찾아 염
	std::ifstream in("test.txt");
	std::string s;
	
	if (in.is_open()) { // 파일이 성공적으로 열렸는지 여부 확인
		in >> s; // 공백이 나올 때까지 읽음
		std::cout << "입력 받은 문자열 :: " << s << std::endl;
	} else {
		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
	}
	return (0); // ifstream  객체 소멸자가 알아서 파일 close해줌
}

