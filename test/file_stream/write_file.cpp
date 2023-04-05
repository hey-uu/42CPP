#include <iostream>
#include <fstream>

// int	main(void)
// {
// 	std::ofstream out("test2.txt"); 
// 		// test2.txt가 없으면 생성함
// 		//             있으면 덮어 씌움

// 	if (out.is_open()) {
// 		out << "이걸 쓰자!";
// 	}
// }

int	main(void)
{
	std::ofstream out("test2.txt", std::ios::app); 
		// test2.txt가 없으면 생성함
		//             있으면 이어서 작성

	if (out.is_open()) {
		out << "덧붙이자!";
	}
}