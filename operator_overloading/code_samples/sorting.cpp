#include "csv.h"
#include "Superhero.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv){
	io::CSVReader<5, io::trim_chars<' '>, io::double_quote_escape<',','\"'> > in("marvel.csv");
	in.read_header(io::ignore_extra_column, "page_id", "name", "ALIGN", "EYE", "HAIR");

	std::vector<Superhero> heroes;

	int id;
	std::string name;
	std::string alignment;
	std::string eye;
	std::string hair;

	while(in.read_row(id, name, alignment, eye, hair)){
		// do stuff with the data
		Superhero tmp(id, name, alignment, eye, hair);
		heroes.push_back(tmp);
	}

	std::sort(heroes.begin(), heroes.end());
	for(int i=0; i<10; i++){
		std::cout << heroes[i] << std::endl;
	}
}
