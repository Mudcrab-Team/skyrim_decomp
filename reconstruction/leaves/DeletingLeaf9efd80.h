// Source exposure: binary-analysis
// DeletingLeaf9efd80, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9efd80 {
public:
    virtual ~DeletingLeaf9efd80() {}
};
static_assert(sizeof(DeletingLeaf9efd80) == 8, "minimal virtual interface size");
