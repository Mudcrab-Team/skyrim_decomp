// Source exposure: binary-analysis
// DeletingLeaf846640, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf846640 {
public:
    virtual ~DeletingLeaf846640() {}
};
static_assert(sizeof(DeletingLeaf846640) == 8, "minimal virtual interface size");
