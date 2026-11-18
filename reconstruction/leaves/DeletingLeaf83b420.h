// Source exposure: binary-analysis
// DeletingLeaf83b420, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf83b420 {
public:
    virtual ~DeletingLeaf83b420() {}
};
static_assert(sizeof(DeletingLeaf83b420) == 8, "minimal virtual interface size");
