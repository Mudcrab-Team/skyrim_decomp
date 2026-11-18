// Source exposure: binary-analysis
// DeletingLeaf849940, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf849940 {
public:
    virtual ~DeletingLeaf849940() {}
};
static_assert(sizeof(DeletingLeaf849940) == 8, "minimal virtual interface size");
