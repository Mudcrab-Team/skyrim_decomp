// Source exposure: binary-analysis
// DeletingLeaf841d40, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf841d40 {
public:
    virtual ~DeletingLeaf841d40() {}
};
static_assert(sizeof(DeletingLeaf841d40) == 8, "minimal virtual interface size");
