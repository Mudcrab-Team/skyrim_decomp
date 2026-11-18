// Source exposure: binary-analysis
// DeletingLeaf82fd50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf82fd50 {
public:
    virtual ~DeletingLeaf82fd50() {}
};
static_assert(sizeof(DeletingLeaf82fd50) == 8, "minimal virtual interface size");
