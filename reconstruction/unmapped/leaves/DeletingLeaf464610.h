// Source exposure: binary-analysis
// DeletingLeaf464610, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf464610 {
public:
    virtual ~DeletingLeaf464610() {}
};
static_assert(sizeof(DeletingLeaf464610) == 8, "minimal virtual interface size");
