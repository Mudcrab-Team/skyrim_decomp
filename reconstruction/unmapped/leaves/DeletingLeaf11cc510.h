// Source exposure: binary-analysis
// DeletingLeaf11cc510, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf11cc510 {
public:
    virtual ~DeletingLeaf11cc510() {}
};
static_assert(sizeof(DeletingLeaf11cc510) == 8, "minimal virtual interface size");
