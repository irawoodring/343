#include "csv.h"
#include "Superhero.h"
#include <iostream>
#include <queue>

int main(int argc, char** argv){
	io::CSVReader<5, io::trim_chars<' '>, io::double_quote_escape<',','\"'> > in("marvel.csv");
	in.read_header(io::ignore_extra_column, "page_id", "name", "ALIGN", "EYE", "HAIR");

	std::priority_queue<Superhero> heroes;

	int id;
	std::string name;
	std::string alignment;
	std::string eye;
	std::string hair;

	while(in.read_row(id, name, alignment, eye, hair)){
		// do stuff with the data
		Superhero tmp(id, name, alignment, eye, hair);
		std::cout << id << ", " << name << ", " << eye << ", " << hair << std::endl;
		heroes.push(tmp);
	}

	std::cout << "Entered " << heroes.size() << " heroes into priority queue." << std::endl;
	std::cout << heroes.top() << std::endl;
}
