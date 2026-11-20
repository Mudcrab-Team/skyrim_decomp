// Source exposure: binary-analysis
// DeletingLeaf450000, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf450000 {
public:
    virtual ~DeletingLeaf450000() {}
};
static_assert(sizeof(DeletingLeaf450000) == 8, "minimal virtual interface size");
