//#include "BitArray.h"
//#include <algorithm> 
//
////BitArray::BitArray() {
////}
//
//BitArray::~BitArray() {
//    free(bites);
//}
//
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
//
//BitArray::BitArray(const BitArray& b)
//{
//}
