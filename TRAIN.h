#pragma once
#include <string>
#include <iostream>
class TRAIN
{

	std::string name;
	int number;
	std::string time;

public:
	TRAIN();
	TRAIN(int _number, std::string _name, std::string _time);
	TRAIN(const TRAIN& obj);
	void setName(std::string _name);
	void setNumber(int _number);
	void setTime(std::string _time);
	std::string getName();
	int getNumber();
	std::string getTime();
	friend std::ostream& operator<<(std::ostream& out, const TRAIN& other);

};

