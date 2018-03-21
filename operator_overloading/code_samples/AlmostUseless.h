#ifndef			__H__ALMOSTUSELESS__
#define			__H__ALMOSTUSELESS__

#include <vector>
#include <ctime>

template <typename T>
class AlmostUseless {
	public:
		AlmostUseless(){
			std::srand(std::time(nullptr));
		}

		const T & operator[](int i){
			return data[rand() % data.size() + 1];
		}

		void insert(const T & something){
			data.push_back(something);
		}
	private:
		std::vector<T> data;
};

#endif
