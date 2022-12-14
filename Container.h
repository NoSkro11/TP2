#pragma once
#include "List.h"
#include"TRAIN.h"
#include<fstream>
class Container
{

	List<TRAIN> trains;
public:
	Container();
	void parse(std::string _line, int& _num, std::string& _name, std::string& _time);
	void sort(std::string* arr, int j);
	void find();
	void addTr();
	void delTr();
	void save();
	void recovery();
	void change();
	void show();
	void allSort();
	void init();
};

