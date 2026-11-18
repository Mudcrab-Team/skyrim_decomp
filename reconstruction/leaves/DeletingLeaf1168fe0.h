// Source exposure: binary-analysis
// DeletingLeaf1168fe0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1168fe0 {
public:
    virtual ~DeletingLeaf1168fe0() {}
};
static_assert(sizeof(DeletingLeaf1168fe0) == 8, "minimal virtual interface size");
