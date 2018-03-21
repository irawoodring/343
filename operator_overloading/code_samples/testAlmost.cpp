#include "AlmostUseless.h"
#include <iostream>

int main(int argc, char** argv){
	AlmostUseless<int> nums;
	
	for(int i=0; i<100; i++){
		nums.insert(i);
	}

	std::cout << nums[1] << std::endl;
}
