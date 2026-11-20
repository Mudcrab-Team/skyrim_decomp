// Source exposure: binary-analysis
// DeletingLeaf893ab0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf893ab0 {
public:
    virtual ~DeletingLeaf893ab0() {}
};
static_assert(sizeof(DeletingLeaf893ab0) == 8, "minimal virtual interface size");
