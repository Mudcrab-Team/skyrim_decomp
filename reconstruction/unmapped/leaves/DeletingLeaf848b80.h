// Source exposure: binary-analysis
// DeletingLeaf848b80, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf848b80 {
public:
    virtual ~DeletingLeaf848b80() {}
};
static_assert(sizeof(DeletingLeaf848b80) == 8, "minimal virtual interface size");
