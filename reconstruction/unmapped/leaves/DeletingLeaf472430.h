// Source exposure: binary-analysis
// DeletingLeaf472430, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf472430 {
public:
    virtual ~DeletingLeaf472430() {}
};
static_assert(sizeof(DeletingLeaf472430) == 8, "minimal virtual interface size");
