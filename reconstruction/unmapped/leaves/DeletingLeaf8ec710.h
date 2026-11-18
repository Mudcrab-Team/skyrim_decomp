// Source exposure: binary-analysis
// DeletingLeaf8ec710, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8ec710 {
public:
    virtual ~DeletingLeaf8ec710() {}
};
static_assert(sizeof(DeletingLeaf8ec710) == 8, "minimal virtual interface size");
