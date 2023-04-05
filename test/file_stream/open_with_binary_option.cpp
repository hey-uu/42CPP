#include <iostream>
#include <fstream>

int	main(void)
{
	// 파일을 bianry 형태로 받고자 할 때
	std::ifstream	in("test.txt", std::ios::binary);
	int				x;

	if (in.is_open()) {
		in.read((char *)(&x), 4); 
		// 4바이트만큼 읽어라. int 변수 = 4바이트짜리 char 배열
		// 실제로는 보통 char 배열을 지정해서 인자로 넣어줌
		std::cout << std::hex << x << std::endl;
		// std::hex : 출력 포맷팅 : 정수를 16진수로 표현해줌
	} else {
		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
	}
	return (0);
}