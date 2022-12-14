#include "TRAIN.h"

TRAIN::TRAIN()
{
	this->name = "";
	this->number = 0;
	this->time = "";
}

TRAIN::TRAIN(int _number, std::string _name, std::string _time): name(_name), number(_number), time(_time)
{


}

TRAIN::TRAIN(const TRAIN& obj)
{
	this->name = obj.name;
	this->number = obj.number;
	this->time = obj.time;
}

void TRAIN::setName(std::string _name)
{
	this->name = _name;
}

void TRAIN::setNumber(int _number)
{
	this->number = _number;
}

void TRAIN::setTime(std::string _time)
{
	this->time = _time;

}

std::string TRAIN::getName()
{
	return this->name;
}

int TRAIN::getNumber()
{
	return this->number;
}

std::string TRAIN::getTime()
{
	return this->time;
}

std::ostream& operator<<(std::ostream& out, const TRAIN& other)
{

	out << other.name << "\tN:"<<other.number<<"\tstart: "<<other.time<<"\n";

	return out;
}
