#ifndef			__H_SUPERHERO__
#define			__H_SUPERHERO__

#include <string>
#include <iostream>

class Superhero {
	public:
		Superhero(int id, std::string name, std::string affiliation, std::string eye, std::string hair);
		int getId() const;
		std::string getName() const;
		std::string getAffiliation() const;
		std::string getEye() const;
		std::string getHair() const;
		friend bool operator< (const Superhero & lhs, const Superhero & rhs);
		friend std::ostream & operator<< (std::ostream & os, const Superhero & obj);

	private:
		int id;
		std::string name;
		std::string affiliation;
		std::string eye;
		std::string hair;
};


#endif
