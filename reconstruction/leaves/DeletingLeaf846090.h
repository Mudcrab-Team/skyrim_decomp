// Source exposure: binary-analysis
// DeletingLeaf846090, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf846090 {
public:
    virtual ~DeletingLeaf846090() {}
};
static_assert(sizeof(DeletingLeaf846090) == 8, "minimal virtual interface size");
