// Source exposure: binary-analysis
// DeletingLeafce1ce0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafce1ce0 {
public:
    virtual ~DeletingLeafce1ce0() {}
};
static_assert(sizeof(DeletingLeafce1ce0) == 8, "minimal virtual interface size");
