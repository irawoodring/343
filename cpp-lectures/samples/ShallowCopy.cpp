#include <iostream>

class Student {
	public:
		int number;
		float gpa;
		float* grades;
};

int main(int argc, char** argv){
	Student a;
	a.grades = new float[50];
	a.grades[0] = 100;
	Student b(a);
	b.grades[0] = 46;
	std::cout << "Student a got a " << a.grades[0] << std::endl;
}
