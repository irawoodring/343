#include <iostream>
#include <utility>
#include <vector>

class Student {
	public:

		// Because we are overriding the constructor,
		// we need to provide a new default one as well.
		Student(){
			std::cout << "Default constructor called." << std::endl;
			grades = new float[50];
		}		

		Student(const Student& other){
			std::cout << "Copy constructor called." << std::endl;
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

		/*
		 * Copy Operator=
		 * Pass copy of object in (will call
		 * the copy constructor!).  Then
		 * steal its data.
		 */
		Student& operator=(Student other){
			std::cout << "Copy Operator= called." << std::endl;
			// Swap our old data for the
			// good new data.
			std::swap(this->number, other.number);
			std::swap(this->gpa, other.gpa);
			std::swap(this->grades, other.grades);
	
			// Return ourself!
			return *this;
		}

		/*
		 * Move Constructor
		 * Notice the &&.
		 */
		Student(Student&& other){
			std::cout << "Move Constructor called." << std::endl;
			if (this != &other){
				// Steal the other object's data
				this->number = std::move(other.number);
				this->gpa = std::move(other.gpa);
		
				// Steal the other object's grades
				this->grades = std::move(other.grades);
					
				// Set the other object's pointer to nullptr.
				// Otherwise, when it dies it will take
				// our stolen data with it.
				other.grades = nullptr;
			}
		}
		
		/*
		 * Destructor
		 */
	
		~Student(){
			delete[] grades;
		}

		Student getNewStudent(){
			Student tmp;
			return tmp;
		}

		int number;
		float gpa;
		float* grades;
};

int main(int argc, char** argv){
	std::cout << "----------------------------------------" << std::endl;
	Student a;
	a.grades[0] = 100;
	std::cout << "----------------------------------------" << std::endl;
	Student b(a);
	b.grades[0] = 46;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Student a got a " << a.grades[0] << std::endl;
	std::cout << "Student b got a " << b.grades[0] << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::vector<Student> students;
	students.push_back(Student());	
	std::cout << "----------------------------------------" << std::endl;
	// We aren't going into the Move Operator=.  
	// Read up on Move semantics and the unifying operator=.
}
