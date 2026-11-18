// Source exposure: binary-analysis
// DeletingLeaf997210, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf997210 {
public:
    virtual ~DeletingLeaf997210() {}
};
static_assert(sizeof(DeletingLeaf997210) == 8, "minimal virtual interface size");
