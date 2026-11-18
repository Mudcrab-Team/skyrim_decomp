// Source exposure: binary-analysis
// DeletingLeaf324860, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf324860 {
public:
    virtual ~DeletingLeaf324860() {}
};
static_assert(sizeof(DeletingLeaf324860) == 8, "minimal virtual interface size");
