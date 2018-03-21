#include "Superhero.h"

Superhero::Superhero(int id, std::string name, std::string affiliation, std::string eye, std::string hair){
	this->id = id;
	this->name = name;
	this->affiliation = affiliation;
	this->eye = eye;
	this->hair = hair;
}

bool operator< (const Superhero & lhs, const Superhero & rhs){
	return lhs.id < rhs.id;
}

std::ostream & operator<< (std::ostream & os, const Superhero & obj){
	return os << obj.name << " has " << obj.eye << " eyes, " << obj.hair << " hair, and is " << obj.affiliation << ".";
}
