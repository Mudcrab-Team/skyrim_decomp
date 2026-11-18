// Source exposure: binary-analysis
// DeletingLeaf651230, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf651230 {
public:
    virtual ~DeletingLeaf651230() {}
};
static_assert(sizeof(DeletingLeaf651230) == 8, "minimal virtual interface size");
