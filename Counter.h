#pragma once
#include<iostream>
#include<fstream>
#include<string>

class Counter {

	std::string path;
	int lenWord;
public:
	Counter();
	Counter(std::string _path, int _lenWord);
	int count();
	int parse(std::string _str);
	

};

