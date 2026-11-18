// Source exposure: binary-analysis
// DeletingLeaf461bc0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf461bc0 {
public:
    virtual ~DeletingLeaf461bc0() {}
};
static_assert(sizeof(DeletingLeaf461bc0) == 8, "minimal virtual interface size");
