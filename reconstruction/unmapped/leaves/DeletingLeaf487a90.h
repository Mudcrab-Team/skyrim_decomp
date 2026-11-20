// Source exposure: binary-analysis
// DeletingLeaf487a90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf487a90 {
public:
    virtual ~DeletingLeaf487a90() {}
};
static_assert(sizeof(DeletingLeaf487a90) == 8, "minimal virtual interface size");
