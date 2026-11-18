// Source exposure: binary-analysis
// DeletingLeaf830220, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830220 {
public:
    virtual ~DeletingLeaf830220() {}
};
static_assert(sizeof(DeletingLeaf830220) == 8, "minimal virtual interface size");
