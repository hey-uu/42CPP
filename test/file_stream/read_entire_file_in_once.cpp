#include <iostream>
#include <fstream>
#include <string>

int	main(void)
{
	std::ifstream	in("test.txt");
	std::string		s;

	if (in.is_open())
	{
		// 위치 지정자를 파일 끝으로 옮기자.
		in.seekg(0, std::ios::end);
			// 두 번째 인자 = 파일 내 위치
			// 첫 번재 인자 = 두 번째 인자로부터 얼마나 떨어져 있는가.
		// 그리고 그 위치를 읽자 (위치=크기)
		int size = in.tellg();
		std::cout << "pos : " << size << "\n";
		// 크기만큼 문자열의 크기 재할당
		s.resize(size);
		// 위치 지정자를 다시 파일의 맨 앞으로 옮기자.
		in.seekg(0, std::ios::beg);
		// 파일 전체 내용을 읽어서 문자열에 저장하기
		in.read(&s[0], size);
		std::cout << s << std::endl;
	} else {
		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
	}
	return (0);
}