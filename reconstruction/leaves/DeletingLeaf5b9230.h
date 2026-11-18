// Source exposure: binary-analysis
// DeletingLeaf5b9230, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf5b9230 {
public:
    virtual ~DeletingLeaf5b9230() {}
};
static_assert(sizeof(DeletingLeaf5b9230) == 8, "minimal virtual interface size");
