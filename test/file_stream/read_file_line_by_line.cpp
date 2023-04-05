#include <iostream>
#include <fstream>
#include <string>

// int	main(void)
// {
// 	std::ifstream	in("test.txt");
// 	char			buf[100];

// 	if (!in.is_open()) {
// 		std::cout << "파일을 찾을 수 없습니다!\n";
// 		return (0);
// 	}
//  // ifstream에는 operator bool() 연산자가 오버로딩되어 있음
//  // 값이 true려면 다음 읽기 작업이 성공적이어야하고 오류 플래그가 켜져 있지 말아야한다.
// 	while (in) {
// 		in.getline(buf, 100);
// 		// 개행 문자가 나올 때까지 최대 지정한 크기 - 1만큼 읽는다.
// 		// 개행 문자말고 직접 지정한 문자가 나올 때가지 읽는 것으로 바꿀 수도 있음
// 		// 개행 문자가 나오기 전에 지정한 버퍼의 크기가 다 차면 failbit가 켜지므로 주의해야함
// 		// 이 한계를 극복하기 위해서 string에서 getline 함수를 제공하고 있음음
// 		std::cout << buf << "\n";
// 	}
// 	return (0);
// }


int	main(void)
{
	std::ifstream	in("test.txt");
	std::string		s;

	if (!in.is_open()) {
		std::cout << "파일을 찾을 수 없습니다!\n";
		return (0);
	}
	while (in) {
		getline(in, s);
		std::cout << s << "\n";
	}
	return (0);
}