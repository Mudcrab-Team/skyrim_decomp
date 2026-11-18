// Source exposure: binary-analysis
// DeletingLeaf11d2f60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf11d2f60 {
public:
    virtual ~DeletingLeaf11d2f60() {}
};
static_assert(sizeof(DeletingLeaf11d2f60) == 8, "minimal virtual interface size");
