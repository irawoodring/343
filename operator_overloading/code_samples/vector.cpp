#include "csv.h"
#include "Superhero.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv){
	io::CSVReader<5, io::trim_chars<' '>, io::double_quote_escape<',','\"'> > in("marvel.csv");
	in.read_header(io::ignore_extra_column, "page_id", "name", "ALIGN", "EYE", "HAIR");

	std::vector<Superhero> heros;

	int id;
	std::string name;
	std::string alignment;
	std::string eye;
	std::string hair;

	while(in.read_row(id, name, alignment, eye, hair)){
		// do stuff with the data
		std::cout << name << std::endl;
		Superhero tmp(id, name, alignment, eye, hair);
		heros.push_back(tmp);
	}

	std::cout << "Entered " << heros.size() << " heros into vector." << std::endl;
}
