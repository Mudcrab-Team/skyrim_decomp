// Source exposure: binary-analysis
// DeletingLeaf85e240, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf85e240 {
public:
    virtual ~DeletingLeaf85e240() {}
};
static_assert(sizeof(DeletingLeaf85e240) == 8, "minimal virtual interface size");
