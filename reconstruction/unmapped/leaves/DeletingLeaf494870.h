// Source exposure: binary-analysis
// DeletingLeaf494870, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf494870 {
public:
    virtual ~DeletingLeaf494870() {}
};
static_assert(sizeof(DeletingLeaf494870) == 8, "minimal virtual interface size");
