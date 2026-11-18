// Source exposure: binary-analysis
// DeletingLeafeb27a0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafeb27a0 {
public:
    virtual ~DeletingLeafeb27a0() {}
};
static_assert(sizeof(DeletingLeafeb27a0) == 8, "minimal virtual interface size");
