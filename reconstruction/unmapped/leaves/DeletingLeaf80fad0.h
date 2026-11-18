// Source exposure: binary-analysis
// DeletingLeaf80fad0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf80fad0 {
public:
    virtual ~DeletingLeaf80fad0() {}
};
static_assert(sizeof(DeletingLeaf80fad0) == 8, "minimal virtual interface size");
