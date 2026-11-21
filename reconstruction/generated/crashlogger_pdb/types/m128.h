// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: __m128; size 0x10
#pragma once
union m128 {
    float* m128_f32_0[2];
    unsigned long long m128_u64_0[2];
    char m128_i8_0[16];
    short m128_i16_0[8];
    int m128_i32_0[4];
    long long m128_i64_0[2];
    unsigned char m128_u8_0[16];
    unsigned short m128_u16_0[8];
    unsigned int m128_u32_0[4];
};
static_assert(sizeof(m128) == 16, "m128 layout differs from the PDB");
