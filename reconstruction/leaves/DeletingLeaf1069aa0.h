// Source exposure: binary-analysis
// DeletingLeaf1069aa0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1069aa0 {
public:
    virtual ~DeletingLeaf1069aa0() {}
};
static_assert(sizeof(DeletingLeaf1069aa0) == 8, "minimal virtual interface size");
