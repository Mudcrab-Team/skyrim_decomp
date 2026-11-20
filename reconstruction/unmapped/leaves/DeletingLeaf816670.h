// Source exposure: binary-analysis
// DeletingLeaf816670, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf816670 {
public:
    virtual ~DeletingLeaf816670() {}
};
static_assert(sizeof(DeletingLeaf816670) == 8, "minimal virtual interface size");
