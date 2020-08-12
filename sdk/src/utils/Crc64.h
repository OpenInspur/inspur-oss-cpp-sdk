
#pragma once
#include <stdint.h>
#include <cstddef>
namespace InspurCloud
{
namespace OSS
{
    class CRC64
    {
    public:
        static uint64_t CalcCRC(uint64_t crc, void *buf, size_t len);
        static uint64_t CombineCRC(uint64_t crc1, uint64_t crc2, uintmax_t len2);
    };
}
}

