// Source exposure: binary-analysis
// DeletingLeaf846f00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf846f00 {
public:
    virtual ~DeletingLeaf846f00() {}
};
static_assert(sizeof(DeletingLeaf846f00) == 8, "minimal virtual interface size");
