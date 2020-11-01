#pragma once


#include <inttypes.h>
#include <cmath>
namespace QtCommon2 {

    inline int64_t ipow(int64_t base, uint8_t exp) {
        static const uint8_t highest_bit_set[] = {
            0, 1, 2, 2, 3, 3, 3, 3,
            4, 4, 4, 4, 4, 4, 4, 4,
            5, 5, 5, 5, 5, 5, 5, 5,
            5, 5, 5, 5, 5, 5, 5, 5,
            6, 6, 6, 6, 6, 6, 6, 6,
            6, 6, 6, 6, 6, 6, 6, 6,
            6, 6, 6, 6, 6, 6, 6, 6,
            6, 6, 6, 6, 6, 6, 6, 255, // anything past 63 is a guaranteed overflow with base > 1
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
            255, 255, 255, 255, 255, 255, 255, 255,
        };

        int64_t result = 1;

        switch (highest_bit_set[exp]) {
        case 255: // we use 255 as an overflow marker and return 0 on overflow/underflow
            if (base == 1) {
                return 1;
            }

            if (base == -1) {
                return 1 - 2 * (exp & 1);
            }

            return 0;
        case 6:
            if (exp & 1) result *= base;
            exp >>= 1;
            base *= base;
        [[fallthrough]]; case 5:
            if (exp & 1) result *= base;
            exp >>= 1;
            base *= base;
        [[fallthrough]]; case 4:
            if (exp & 1) result *= base;
            exp >>= 1;
            base *= base;
        [[fallthrough]]; case 3:
            if (exp & 1) result *= base;
            exp >>= 1;
            base *= base;
        [[fallthrough]]; case 2:
            if (exp & 1) result *= base;
            exp >>= 1;
            base *= base;
        [[fallthrough]]; case 1:
            if (exp & 1) result *= base;
        [[fallthrough]]; default:
            return result;
        }
    }

    inline double round(double d, int decimalPoints) {
        long f = static_cast<long>(pow(10,decimalPoints));
        return floor(d*f  + 0.5 ) / f;
    }

    inline double round2Decimals(double d) {
        return floor(d* 100 + 0.5 ) / 100;
    }

    inline int ceiling(float f)
    {
        return static_cast<int>(ceil(f));
    }

    inline unsigned int ceilingUInt(float f)
    {
        return static_cast<unsigned int>(ceil(f));
    }

    inline unsigned long long ceilingUInt64(double d)
    {
        return static_cast<unsigned long long>(ceil(d));
    }



}
  