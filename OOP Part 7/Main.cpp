#include <iostream>
#include <queue>
#include <stack>
#include <vector>
// Коллекции и шаблонные классы
// Типы коллекций 
// - линейные массивы
//		* динамический (vector)
//		* статический  (array)
// - списки
//		* односвязные  (forward_list)
//		* двусвязные списки (list)
//			* кольца
// - деревья (set,map и их производные)
// - графы	 	
//-------------------
// Способы использования коллекций
// * очереди (FirstInFirstOut) | (queue)
// * стеки	 (FirstInLastOut)  | (stack)
//

class DinamiArray {
public:
	DinamiArray() :data_(nullptr), size_(0) {};

	//конструктор копирования
	DinamiArray(const DinamiArray& other) {
		size_ = other.size_;
		data_ = new float[size_];
		for (int i = 0; i < size_; i++) {
			data_[i] = other.data_[i];
		}
	}
	//Конструктор переноса
	DinamiArray(DinamiArray&& other) {
		size_ = other.size_;
		data_ = nullptr;
		std::swap(data_, other.data_);
		std::swap(size_, other.size_);
	}


	~DinamiArray() {
		if (data_) {
			delete[]data_;
		}
	}

	void AddBack(float value) {
		if (data_) {
			auto tmp = new float[size_ + 1];
			for (int i = 0; i < size_; i++) {
				tmp[i] = data_[i];
			}
			tmp[size_] = value;
			std::swap(tmp, data_);
			size_ += 1;
			delete[]tmp;

		}
		else {
			data_ = new float[1] {value};
			size_ += 1;
		}
	}

	void PopBack() {
		if (data_) {
			auto tmp = new float[size_ - 1];
			for (int i = 0; i < size_; i++) {
				tmp[i] = data_[i];
			}
			std::swap(tmp, data_);
			size_ -= 1;
			delete[]tmp;
			if (size_ == 0) {
				delete[]data_;
				data_ = nullptr;
			}
		}
	}

	float& operator[](int n) {
		return data_[n];
	}

	const float& operator[](int n)const {
		return data_[n];
	}
	//оператор присваивания копированием
	DinamiArray& operator = (const DinamiArray& other) {
		if (data_) {
			delete[] data_;
		}
		size_ = other.size_;
		data_ = new float[size_];
		for (int i = 0; i < size_; i++) {
			data_[i] = other.data_[i];
		}
		return *this;
	}

	//оператор присваивания переносом
	DinamiArray& operator = (DinamiArray&& other) {
		std::swap(data_, other.data_);
		std::swap(size_, other.size_);
		return *this;
	}
		

private:
	float* data_;
	int size_;
	//int capacity_; требуется для более сложной но эфективной работы с выделенной памятью


};

void FOO(DinamiArray obj){}

DinamiArray Gen(int length) {
	DinamiArray result;
	for (size_t i = 0; i < length; i++) {
		result.AddBack(::rand() % 10);
	}
	return result;
}

int main() {
	setlocale(LC_ALL, "ru");

	const float arr[123]{};
	DinamiArray arrd;
	arrd.AddBack(1234.5);
	std::cout << arrd[0];
	arr[0];
	arrd[0];
	FOO(arrd);

	DinamiArray arrd2;
	arrd2 = arrd;

	return 0;
}