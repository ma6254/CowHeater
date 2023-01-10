#ifndef BYTES_H
#define BYTES_H

#include "c51_type.h"

#define Pack_H8L4(h, l, bufx) ((l) = (uint8_t)(bufx >> 0), (h) = (uint8_t)(bufx >> 8))
#define Pack_H8L4_LF(h, l, bufx) ((l) = (uint8_t)(bufx >> 0), (h) = (uint8_t)(bufx >> 8))
#define Read_H8L4(h, l) ((uint16_t)((uint8_t)h) << 8 | (uint16_t)((uint8_t)l) << 0)

// 拼装多字节数据
// BigEndian 大头序 高位在前
#define UnPack_Big_16(bufx) ((((uint16_t) * (bufx + 0)) << 8) | (((uint16_t) * (bufx + 1)) << 0))
#define UnPack_Big_32(bufx) ((((uint32_t) * (bufx + 0)) << 24) | (((uint32_t) * (bufx + 1)) << 16) | (((uint32_t) * (bufx + 2)) << 8) | (((uint32_t) * (bufx + 3)) << 0))
#define Pack_Big_16(bufx, x)                         \
    {                                                \
        *(bufx + 0) = (uint8_t)((uint16_t)(x) >> 8); \
        *(bufx + 1) = (uint8_t)((uint16_t)(x) >> 0); \
    }
#define Pack_Big_32(bufx, x)              \
    {                                     \
        *(bufx + 0) = (uint8_t)(x >> 24); \
        *(bufx + 1) = (uint8_t)(x >> 16); \
        *(bufx + 2) = (uint8_t)(x >> 8);  \
        *(bufx + 3) = (uint8_t)(x >> 0);  \
    }

// LittleEndian 小头序 低位在前
#define UnPack_Little_16(bufx) ((((uint16_t) * (bufx + 0)) << 0) | (((uint16_t) * (bufx + 1)) << 8))
#define UnPack_Little_32(bufx) ((((uint32_t) * (bufx + 0)) << 0) | (((uint32_t) * (bufx + 1)) << 8) | (((uint32_t) * (bufx + 2)) << 16) | (((uint32_t) * (bufx + 3)) << 24))
#define Pack_Little_16(bufx, x)          \
    {                                    \
        *(bufx + 0) = (uint8_t)(x >> 0); \
        *(bufx + 1) = (uint8_t)(x >> 8); \
    }
#define Pack_Little_32(bufx, x)           \
    {                                     \
        *(bufx + 0) = (uint8_t)(x >> 0);  \
        *(bufx + 1) = (uint8_t)(x >> 8);  \
        *(bufx + 2) = (uint8_t)(x >> 16); \
        *(bufx + 3) = (uint8_t)(x >> 24); \
    }

#endif /* End of BYTES_H */
