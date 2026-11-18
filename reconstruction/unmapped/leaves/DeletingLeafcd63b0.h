// Source exposure: binary-analysis
// DeletingLeafcd63b0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafcd63b0 {
public:
    virtual ~DeletingLeafcd63b0() {}
};
static_assert(sizeof(DeletingLeafcd63b0) == 8, "minimal virtual interface size");
