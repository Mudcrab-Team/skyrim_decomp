// Source exposure: binary-analysis
// DeletingLeaf472320, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf472320 {
public:
    virtual ~DeletingLeaf472320() {}
};
static_assert(sizeof(DeletingLeaf472320) == 8, "minimal virtual interface size");
