// Source exposure: binary-analysis
// DeletingLeaf450140, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf450140 {
public:
    virtual ~DeletingLeaf450140() {}
};
static_assert(sizeof(DeletingLeaf450140) == 8, "minimal virtual interface size");
