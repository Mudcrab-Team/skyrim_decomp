// Source exposure: binary-analysis
// DeletingLeaf651200, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf651200 {
public:
    virtual ~DeletingLeaf651200() {}
};
static_assert(sizeof(DeletingLeaf651200) == 8, "minimal virtual interface size");
