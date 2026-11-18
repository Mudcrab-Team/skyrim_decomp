// Source exposure: binary-analysis
// DeletingLeaf858780, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf858780 {
public:
    virtual ~DeletingLeaf858780() {}
};
static_assert(sizeof(DeletingLeaf858780) == 8, "minimal virtual interface size");
