// Source exposure: binary-analysis
// DeletingLeaf467d00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf467d00 {
public:
    virtual ~DeletingLeaf467d00() {}
};
static_assert(sizeof(DeletingLeaf467d00) == 8, "minimal virtual interface size");
