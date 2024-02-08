#include <iostream>
#include <list>

template <typename T>
class LinearAllocator {
public:
    LinearAllocator(size_t size) {
        data_.resize(size);
        current_ = data_.begin();  // ��������� current_ ��������������� �� ������ ������
    }

    T* allocate(size_t size) {  // ��������� ����� ������ ��������� �������
        if (std::distance(current_, data_.end()) < size)  // ���������, ���������� �� ���������� ����� � ������ ��� ��������� ���������� �������
            return nullptr;  // ���� ���, ������������ nullptr

        T* ptr = &(*current_);
        std::advance(current_, size);
        return ptr;
    }

    void deallocate(T* ptr, size_t size) {  // ������������ ��� ������������ ����� ����������� ����� ������
        if (ptr >= &(*data_.begin()) && ptr < &(*data_.end()))  // ���������, ��������� �� ��������� ptr � �������� ������
            current_ = std::next(data_.begin(), std::distance(&(*data_.begin()), ptr));  // ���� ��, �� ��������� current_ ��������������� �� �������, ��������������� ��������� ptr
    }

private:
    std::list<T> data_;
    typename std::list<T>::iterator current_;
};

int main() {
    LinearAllocator<int> allocator(12);

    int* ptr1 = allocator.allocate(4);
    if (ptr1)  // ���� ��������� ������ �������, �������� ������������� ���������������� ���������
        *ptr1 = 1;

    int* ptr2 = allocator.allocate(4);
    if (ptr2)
        *ptr2 = 2;

    int* ptr3 = allocator.allocate(4);
    if (ptr3)
        *ptr3 = 3;

    std::cout << &ptr1 << std::endl;
    std::cout << &ptr2 << std::endl;
    std::cout << &ptr3 << std::endl;

    //allocator.deallocate(ptr1, 4);
    //allocator.deallocate(ptr2, 4);
    //allocator.deallocate(ptr3, 4);

    return 0;
}
