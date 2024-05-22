#include <iostream>
#include <sstream>
#include <fstream>
#include "Lexer.h"

int main(int argc, char const *argv[]) {
	std::ifstream t(argv[1]);
	std::stringstream buffer;
	buffer << t.rdbuf();
	Lexer lexer(std::string(buffer.str()));
	std::vector<Token> tokens = lexer.tokenize();
	for (auto token : tokens) {
		std::cout << token.value << std::endl;
	}
	return 0;
}