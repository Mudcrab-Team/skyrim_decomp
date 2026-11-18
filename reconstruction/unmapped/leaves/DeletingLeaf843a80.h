// Source exposure: binary-analysis
// DeletingLeaf843a80, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf843a80 {
public:
    virtual ~DeletingLeaf843a80() {}
};
static_assert(sizeof(DeletingLeaf843a80) == 8, "minimal virtual interface size");
