// Source exposure: binary-analysis
// DeletingLeaf849a70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf849a70 {
public:
    virtual ~DeletingLeaf849a70() {}
};
static_assert(sizeof(DeletingLeaf849a70) == 8, "minimal virtual interface size");
