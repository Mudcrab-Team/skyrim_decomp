// Source exposure: binary-analysis
// DeletingLeaf848b50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf848b50 {
public:
    virtual ~DeletingLeaf848b50() {}
};
static_assert(sizeof(DeletingLeaf848b50) == 8, "minimal virtual interface size");
