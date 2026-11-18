// Source exposure: binary-analysis
// DeletingLeaf844eb0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf844eb0 {
public:
    virtual ~DeletingLeaf844eb0() {}
};
static_assert(sizeof(DeletingLeaf844eb0) == 8, "minimal virtual interface size");
