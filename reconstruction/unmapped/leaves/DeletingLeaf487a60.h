// Source exposure: binary-analysis
// DeletingLeaf487a60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf487a60 {
public:
    virtual ~DeletingLeaf487a60() {}
};
static_assert(sizeof(DeletingLeaf487a60) == 8, "minimal virtual interface size");
