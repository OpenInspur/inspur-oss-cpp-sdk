
#pragma once
#include <stdint.h>
#include <cstddef>
namespace InspurCloud
{
namespace OSS
{
    class CRC32
    {
    public:
        static uint32_t CalcCRC(uint32_t crc, const void *buf, size_t bufLen);
    };
}
}

