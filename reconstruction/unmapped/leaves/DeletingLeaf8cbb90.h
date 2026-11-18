// Source exposure: binary-analysis
// DeletingLeaf8cbb90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8cbb90 {
public:
    virtual ~DeletingLeaf8cbb90() {}
};
static_assert(sizeof(DeletingLeaf8cbb90) == 8, "minimal virtual interface size");
