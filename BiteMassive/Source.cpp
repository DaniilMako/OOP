#include "bitset.h"

using namespace std;
//using namespace mybitset;

int main() {
    // Test constructor
    mybitset::BitArray bitArray(8); // , bitArray0(8, 0);
    //cout << bitArray.count() << endl;

    //for (int i = 0; i < 8; i++)
    //    cout << bitArray[i];
    //cout << endl;
    //bitArray.swap(bitArray0);
    //for (int i = 0; i < 8; i++)
    //    cout << bitArray[0];
    //auto s = bitArray.to_string();
    //cout << "\n" << s;
    //assert(bitArray.to_string() == "11111111");

    // Test resize and clear
    //bitArray.resize(16);
    //assert(bitArray.size() == 16);
    //assert(bitArray.to_string() == "1111111100000000");

    //bitArray.clear();
    //assert(bitArray.size() == 0);
    //assert(bitArray.empty());

    // Test push_back
    //bitArray.push_back(true);
    //bitArray.push_back(false);
    //assert(bitArray.size() == 2);
    //assert(bitArray.to_string() == "10");

    // Test bitwise operations
    //mybitset::BitArray bitArray1(4, 0b1010);
    //mybitset::BitArray bitArray2(4, 0b1100);

    //bitArray1 &= bitArray2;
    //assert(bitArray1.to_string() == "1000");

    //bitArray1 |= bitArray2;
    //assert(bitArray1.to_string() == "1100");

    //bitArray1 ^= bitArray2;
    //assert(bitArray1.to_string() == "0010");

    // Test bit shifts
    //mybitset::BitArray bitArray3(4, 0b1001);

    //bitArray3 <<= 2;
    //assert(bitArray3.to_string() == "0100");

    //bitArray3 >>= 1;
    //assert(bitArray3.to_string() == "0010");

    //BitArray bitArray4 = bitArray3 << 1;
    //assert(bitArray4.to_string() == "0100");

    //BitArray bitArray5 = bitArray3 >> 1;
    //assert(bitArray5.to_string() == "0001");

    //// Test set and reset
    //bitArray3.set(1, true);
    //assert(bitArray3.to_string() == "0110");

    //bitArray3.reset(2);
    //assert(bitArray3.to_string() == "0100");

    //bitArray3.set();
    //assert(bitArray3.to_string() == "1111");

    //bitArray3.reset();
    //assert(bitArray3.to_string() == "0000");

    //// Test any, none, and count
    //BitArray bitArray6(4, 0b1010);
    //assert(bitArray6.any());
    //assert(!bitArray6.none());
    //assert(bitArray6.count() == 2);

    //BitArray bitArray7(4, 0b0000);
    //assert(!bitArray7.any());
    //assert(bitArray7.none());
    //assert(bitArray7.count() == 0);

    //// Test operator[]
    //BitArray bitArray8(4, 0b1010);
    //assert(bitArray8[0]);
    //assert(!bitArray8[1]);
    //assert(bitArray8[2]);
    //assert(!bitArray8[3]);

    //std::cout << "All tests passed!" << std::endl;

    return 0;
}