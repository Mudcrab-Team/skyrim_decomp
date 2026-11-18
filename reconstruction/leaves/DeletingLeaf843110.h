// Source exposure: binary-analysis
// DeletingLeaf843110, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf843110 {
public:
    virtual ~DeletingLeaf843110() {}
};
static_assert(sizeof(DeletingLeaf843110) == 8, "minimal virtual interface size");
