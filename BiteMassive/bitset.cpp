#include "bitset.h"
#include <iostream>
using namespace std;
namespace mybitset {
    BitArray::BitArray() {
        bites = (unsigned int*)calloc(10, sizeof(unsigned int));
    }
    BitArray::~BitArray() {
        //free(bites);
        delete[] bites;
    }
    //BitArray::BitArray(int num_bits, unsigned long value) {
    //    if (num_bits > 0) {
    //        bites = (unsigned int*)malloc(sizeof(bool) / 8 * num_bits);
    //        for (unsigned long i = 0; i < sizeof(long); i++) {
    //            int idx = i / 32;
    //            int move = i % 32;
    //            if (i >= sizeof(bites)) {
    //                break;
    //            }
    //            if (value == 0) {
    //                bites[idx >> move] & 0;
    //            }
    //            else {
    //                if (value == 1) {
    //                    bites[idx >> move] | 1;
    //                }
    //                else {
    //                    std::out_of_range("Bites must be 1 or 0");
    //                }
    //            }
    //        }
    //        for (unsigned int i = sizeof(long); i < num_bits; i++) {
    //            bites[i] = NULL;
    //        }
    //    }
    //    else {
    //        std::out_of_range("Bitset must contain more than 0 elemets");
    //    }
    //}
    BitArray::BitArray(int num_bits, unsigned long value) {
        if (num_bits > 0) {
            bites[8];// = (unsigned int*)malloc(sizeof(bool) / 8 * num_bits);
            for (int i = 0; i < 8; i++) {
                if (value == 0)
                    cout << 0; //bites[i] = 0;
                else {
                    if (value == 1)
                        bites[i] = 1;
                    else
                        std::cout << "Bites must be 1 or 0" << endl;
                }
            }
        }
        else
            std::cout << "Bitset must contain more than 0 elemets" << endl;
    }
    BitArray::BitArray(const BitArray& b) {
        unsigned int size = sizeof(b.bites);
        bites = (unsigned int*)malloc(size);
        for (unsigned int i = 0; i < size; i++) {
            bites[i] = b.bites[i];
        }
    }
    void BitArray::swap(BitArray& b) {
        if (sizeof(bites) == sizeof(b.bites)) {
            unsigned int temp = 0;
            for (unsigned int i = 0; i < sizeof(bites); i++) {
                temp = bites[i];
                bites[i] = b.bites[i];
                b.bites[i] = temp;
            }
            //free(temp);
        }
        else {
            throw std::out_of_range("Bitsets must be equal");
        }
    }
    //BitArray& BitArray::operator=(const BitArray& b) {
    //    if (sizeof(bites) == sizeof(b.bites)) {
    //        for (unsigned int i = 0; i < sizeof(bites); i++) {
    //            bites[i] = b.bites[i];
    //        }
    //    }
    //    else {
    //        free(bites);
    //        bites = (unsigned int*)malloc(sizeof(b.bites));
    //        for (unsigned int i = 0; i < sizeof(bites); i++) {
    //            bites[i] = b.bites[i];
    //        }
    //    }
    //}
    void BitArray::resize(int num_bits, bool value) {
        if (num_bits == 0) {
            free(bites);
        }
        if (sizeof(bites) == 0) {
            BitArray(num_bits, value);
        }
        else {
            unsigned int* al = (unsigned int*)realloc(bites, sizeof(bool) / 8 * num_bits);
            for (unsigned int i = *al; i < sizeof(bites); i++) {
                int idx = i / 32;
                int move = i % 32;
                if (value == 0) {
                    bites[idx >> move] & 0;
                }
                else {
                    if (value == 1) {
                        bites[idx >> move] | 1;
                    }
                }
            }
        }

    }
    void BitArray::clear() {
        free(bites);
    }
    void BitArray::push_back(bool bit) {
        bool flag = 1;
        for (unsigned int i = 0; i < sizeof(bites); i++) {
            if (i == NULL) {
                flag = 0;
                bites[i >> 1] & bit;
            }
            if (flag == 0) {
                break;
            }
        }
    }
    BitArray& BitArray::operator&=(const BitArray& b) {
        for (unsigned int i = 0; i < sizeof(bites); i++) {
            bites[i] &= b.bites[i];
        }
        return *this;
    }
    BitArray& BitArray::operator|=(const BitArray& b) {
        for (unsigned int i = 0; i < sizeof(bites); i++) {
            bites[i] |= b.bites[i];
        }
        return *this;
    }
    BitArray& BitArray::operator^=(const BitArray& b) {
        for (unsigned int i = 0; i < sizeof(bites); i++) {
            bites[i] ^= b.bites[i];
        }
        return *this;
    }
    BitArray& BitArray::operator<<=(int n) {
        for (unsigned int i = 0; i < sizeof(bites); i++) {
            bites[i] <<= n;
        }
        return *this;
    }
    BitArray& BitArray::operator>>=(int n) {
        for (unsigned int i = 0; i < sizeof(bites); i++) {
            bites[i] <<= n;
        }
        return *this;
    }
    BitArray BitArray::operator<<(int n) const {
        return BitArray();
    }
    //BitArray BitArray::operator>>(int n) const {
    //    return BitArray();
    //}
    //BitArray& BitArray::set(int n, bool val) {
    //    int move = n % 32;
    //    int idx = n / 32;
    //    if (val == 0 && (bites[idx] >> move & 1)) {
    //        bites[idx] -= (1 << move);
    //    }
    //    else {
    //        bites[idx] |= (val << move);
    //    }
    //}
    //BitArray& BitArray::set() {
    //    for (unsigned int i = 0; i < sizeof(bites); i++) {
    //        bites[i] = 1;
    //    }
    //}
    ////BitArray& BitArray::reset(int n) {
    //    int move = n % 32;
    //    int idx = n / 32;
    //    if (bites[idx] >> move & 1) {
    //        bites[idx] -= (1 << move);
    //    }
    //    else {
    //        bites[idx] |= (0 << move);
    //    }
    //}
    //BitArray& BitArray::reset() {
    //    for (unsigned int i = 0; i < sizeof(bites); i++) {
    //        bites[i] = 0;
    //    }
    //}
    bool BitArray::any() const {
        for (int i = 0; i < sizeof(bites); i++) {
            int idx = i / 32;
            int move = i % 32;
            int h = (bites[idx] >> move) & 1;
            if (bites[idx] == 0) {
                i = (idx + 1) * 32 - 1;
            }
            else {
                if (h == 0) {
                    continue;
                }
                else {
                    if (h == 1) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool BitArray::none() const {
        for (int i = 0; i < sizeof(bites); i++) {
            int idx = i / 32;
            int move = i % 32;
            int h = (bites[idx] >> move) & 1;
            if (bites[idx] == 0) {
                i = (idx + 1) * 32 - 1;
            }
            else {
                if (h == 0) {
                    continue;
                }
                else {
                    if (h == 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    //BitArray BitArray::operator~() const {
    //    return BitArray();
    //}
    //int BitArray::count() const {
    //    int count = 0;

    //    for (int i = 0; i < size(); i++) {
    //        if (operator[](i)) {
    //            count++;
    //        }
    //    }

    //    return count;
    //}
    int BitArray::count() const {
        int count = 0;
        for (int i = 0; i < size(); i++)
            if (bites[i] == 1)
                count++;
        return count;
    }
    bool BitArray::operator[](int i) const {
        int move = i % 32;
        int idx = i / 32;
        int h = (bites[idx] >> move) & 1;
        return h;
    }
    int BitArray::size() const {
        return sizeof(bites);
    }
    bool BitArray::empty() const {
        if (sizeof(bites == 0)) {
            return true;
        }
        else {
            return false;
        }
    }
    std::string BitArray::to_string() const {
        std::string str;
        for (unsigned int i = 0; i < sizeof(bites); i++) {
            str += bites[i];
        }
        return str;
    }
}