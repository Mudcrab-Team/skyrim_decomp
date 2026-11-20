// Source exposure: binary-analysis
// DeletingLeafdf7de0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafdf7de0 {
public:
    virtual ~DeletingLeafdf7de0() {}
};
static_assert(sizeof(DeletingLeafdf7de0) == 8, "minimal virtual interface size");
