// Source exposure: binary-analysis
// DeletingLeaf9efc90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9efc90 {
public:
    virtual ~DeletingLeaf9efc90() {}
};
static_assert(sizeof(DeletingLeaf9efc90) == 8, "minimal virtual interface size");
