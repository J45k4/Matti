#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main() {
	std::time_t result = std::time(nullptr);
	std::cout << asctime(std::localtime(&result))
		<< result << " seconds since the Epoch\n";

	system("pause");
}