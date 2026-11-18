// Source exposure: binary-analysis
// DeletingLeaf1123ef0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1123ef0 {
public:
    virtual ~DeletingLeaf1123ef0() {}
};
static_assert(sizeof(DeletingLeaf1123ef0) == 8, "minimal virtual interface size");
