// Source exposure: binary-analysis
// DeletingLeaf846950, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf846950 {
public:
    virtual ~DeletingLeaf846950() {}
};
static_assert(sizeof(DeletingLeaf846950) == 8, "minimal virtual interface size");
