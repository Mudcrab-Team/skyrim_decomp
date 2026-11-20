// Source exposure: binary-analysis
// DeletingLeaf816610, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf816610 {
public:
    virtual ~DeletingLeaf816610() {}
};
static_assert(sizeof(DeletingLeaf816610) == 8, "minimal virtual interface size");
