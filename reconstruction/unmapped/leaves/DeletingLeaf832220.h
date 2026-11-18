// Source exposure: binary-analysis
// DeletingLeaf832220, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf832220 {
public:
    virtual ~DeletingLeaf832220() {}
};
static_assert(sizeof(DeletingLeaf832220) == 8, "minimal virtual interface size");
