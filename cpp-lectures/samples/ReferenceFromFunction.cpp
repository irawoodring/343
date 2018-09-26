/*
 * This may work sometimes, but not other times.
 * You should NEVER do this.
 */

#include <string>
#include <iostream>

class Student {
	public:
		static Student& getNew(){
			Student tmp;
			Student& two = tmp;
			return two;
		}
		std::string name;
		int number;		
};

int main(int argc, char** argv){
	Student ira = Student::getNew();
	ira.name = "Ira";
	ira.number = 9;

	std::cout << ira.name << std::endl;
}
