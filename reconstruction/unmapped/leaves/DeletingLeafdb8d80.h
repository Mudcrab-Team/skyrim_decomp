// Source exposure: binary-analysis
// DeletingLeafdb8d80, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafdb8d80 {
public:
    virtual ~DeletingLeafdb8d80() {}
};
static_assert(sizeof(DeletingLeafdb8d80) == 8, "minimal virtual interface size");
