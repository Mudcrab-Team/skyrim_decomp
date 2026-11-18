// Source exposure: binary-analysis
// DeletingLeaf831140, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf831140 {
public:
    virtual ~DeletingLeaf831140() {}
};
static_assert(sizeof(DeletingLeaf831140) == 8, "minimal virtual interface size");
