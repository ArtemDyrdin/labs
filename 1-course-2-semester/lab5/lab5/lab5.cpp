#include <iostream>
using std::cout; 
using std::endl;
using std::copy;

template<typename T>
class Vector {};

template<>
class Vector<bool> {
private:
	uint8_t* m_arr = nullptr;
	unsigned int m_elements_num = 0;

public:
	void push_back(bool el) {
		/*if (m_elements_num / 8 == 0) {
			uint8_t* new_arr = new uint8_t[m_elements_num / 8 + 1];
			
		}
		if (el)
			m_arr[0] = (m_arr[0] << 1) | 0b00000001;
		else
			m_arr[0] = (m_arr[0] << 1);
		m_elements_num++;*/
	}

	void print() const {
		std::cout << static_cast<int>(m_arr[0]) << std::endl;
	}

	~Vector() {
		if (m_arr != nullptr)
			delete[] m_arr;
	}
};

int main()
{
	Vector<bool> bvect;
	bvect.push_back(true);
	bvect.push_back(false);
	bvect.print();
}
