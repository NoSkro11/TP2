#include"Counter.h"
#include "Counter.h"
#include <string>
#define SYMB " .,:;-«»"
Counter::Counter():path(""), lenWord(0)
{
}
Counter::Counter(std::string _path,int _lenWord) :path(_path), lenWord(_lenWord) {

}
int Counter::count()
{

	std::ifstream f;
	std::string line;
	f.open(path);
	int cnt = 0;
	std::cout << "------------" << path << "-------------\n";
	if (f.is_open()) {
		while (getline(f, line, '\0'))
		{
			std::cout << line;
			cnt += parse(line);

		}
		f.close();
	}
	std::cout << "\n--------------------------------------\n";
	return cnt;
}
int Counter::parse(std::string _str)
{
	char c, prevC;
	int numSymbInWord = 0;
	int i = 0;
	int pos1 = 0, pos2 = 0;
	int cnt = 0;

	while (_str[i] != '\0') {
		c = _str[i];
		if (c == SYMB[0] || c == SYMB[1] || c == SYMB[2] || c == SYMB[3] || c == SYMB[4] || c == SYMB[5] || c == SYMB[6] || c == SYMB[7] || c == SYMB[8] || c == '\n' || c == '\0') {
			prevC = _str[i - 1];
			if ((prevC != SYMB[0] && prevC != SYMB[1] && prevC != SYMB[2] && prevC != SYMB[3] && prevC != SYMB[4] && prevC != SYMB[5] && prevC != SYMB[6] && prevC != SYMB[7] && prevC != SYMB[8]) || i == 0) {
				pos2 = i;
				numSymbInWord = pos2 - pos1;
				pos1 = i;
				if (numSymbInWord <= lenWord)
					cnt++;
			}
			else if (_str[i - 1] == SYMB[0] || _str[i - 1] == SYMB[1] || _str[i - 1] == SYMB[2] || _str[i - 1] == SYMB[3] || _str[i - 1] == SYMB[4] || _str[i - 1] == SYMB[5] || _str[i - 1] == SYMB[6] || _str[i - 1] == SYMB[7] || _str[i - 1] == SYMB[8]) {
				pos2 = i;
				pos1 = i;
			}


		}
		else {
			if (i != 0) {
				if (_str[i - 1] == SYMB[0] || _str[i - 1] == SYMB[1] || _str[i - 1] == SYMB[2] || _str[i - 1] == SYMB[3] || _str[i - 1] == SYMB[4] || _str[i - 1] == SYMB[5] || _str[i - 1] == SYMB[6] || _str[i - 1] == SYMB[7] || _str[i - 1] == SYMB[8]) {
					pos2 = i;
					pos1 = i;
				}
			}
		}

		i++;

	};
	return cnt;
}
