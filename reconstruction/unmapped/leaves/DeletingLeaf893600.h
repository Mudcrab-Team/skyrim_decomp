// Source exposure: binary-analysis
// DeletingLeaf893600, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf893600 {
public:
    virtual ~DeletingLeaf893600() {}
};
static_assert(sizeof(DeletingLeaf893600) == 8, "minimal virtual interface size");
