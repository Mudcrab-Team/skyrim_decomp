// Source exposure: binary-analysis
// DeletingLeaf845970, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf845970 {
public:
    virtual ~DeletingLeaf845970() {}
};
static_assert(sizeof(DeletingLeaf845970) == 8, "minimal virtual interface size");
