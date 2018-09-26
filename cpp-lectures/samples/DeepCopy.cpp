#include <iostream>

class Student {
	public:

		// Because we are overriding the constructor,
		// we need to provide a new default one as well.
		Student(){

		}		

		Student(const Student& other){
			// The first two fields we copy by copy
			this->number = other.number;
			this->gpa = other.gpa;
		
			// This is a pointer though... if we
			// copy by copy we get the address.  We
			// need a new memory area for it.
			this->grades = new float[50];

			// Now copy the old values in.
			for(int i=0; i<50; i++){
				this->grades[i] = other.grades[i];
			}
		}

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
