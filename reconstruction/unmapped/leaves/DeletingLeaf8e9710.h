// Source exposure: binary-analysis
// DeletingLeaf8e9710, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8e9710 {
public:
    virtual ~DeletingLeaf8e9710() {}
};
static_assert(sizeof(DeletingLeaf8e9710) == 8, "minimal virtual interface size");
