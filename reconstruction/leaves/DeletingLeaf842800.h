// Source exposure: binary-analysis
// DeletingLeaf842800, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf842800 {
public:
    virtual ~DeletingLeaf842800() {}
};
static_assert(sizeof(DeletingLeaf842800) == 8, "minimal virtual interface size");
