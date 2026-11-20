// Source exposure: binary-analysis
// DeletingLeaf841d70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf841d70 {
public:
    virtual ~DeletingLeaf841d70() {}
};
static_assert(sizeof(DeletingLeaf841d70) == 8, "minimal virtual interface size");
