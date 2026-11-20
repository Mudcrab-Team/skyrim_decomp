// Source exposure: binary-analysis
// DeletingLeaf496140, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf496140 {
public:
    virtual ~DeletingLeaf496140() {}
};
static_assert(sizeof(DeletingLeaf496140) == 8, "minimal virtual interface size");
