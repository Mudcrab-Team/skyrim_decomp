// Source exposure: binary-analysis
// DeletingLeaf6f0000, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf6f0000 {
public:
    virtual ~DeletingLeaf6f0000() {}
};
static_assert(sizeof(DeletingLeaf6f0000) == 8, "minimal virtual interface size");
