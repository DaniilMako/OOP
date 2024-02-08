//// ДЗ 12
//#include <iostream>
//#include <list>
//
//template <typename T>
//class CustomAllocator :
//        public std::allocator<T> {  // наследуем наш аллокатор от std::allocator
//public:
//	using value_type = T;
//	// конструктор CustomAllocator принимает параметр capacity, который определяет размер блока памяти, выделяемого аллокатором
//	CustomAllocator(size_t capacity) : _capacity(capacity) {  // выделение памяти
//		_memory_block = allocate_block(_capacity);
//	}
//	// деструктор CustomAllocator освобождает выделенный блок памяти с использованием оператора delete.
//	~CustomAllocator() {  // освобождение памяти
//		deallocate_block(_memory_block);
//	}
//
//private:
//	// выделяет блок памяти нужного размера с использованием оператора new
//	value_type* allocate_block(size_t block_size) {
//		return static_cast<value_type*>(::operator new(block_size * sizeof(value_type)));
//	}
//	// освобождает блок памяти с использованием оператора delete
//	void deallocate_block(value_type* block) {
//		::operator delete(block);
//	}
//
//	size_t _capacity;
//	value_type* _memory_block;
//};
//
//int main() {
//	const size_t list_capacity = 10;
//	std::list<int, CustomAllocator<int>> 
//		customList({ 1, 2, 3, 4, 5 }, CustomAllocator<int>(list_capacity));
//
//	for (const auto& element : customList)
//		std::cout << &element << " ";
//
//	return 0;
//}