// Source exposure: binary-analysis
// DeletingLeaf482ab0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf482ab0 {
public:
    virtual ~DeletingLeaf482ab0() {}
};
static_assert(sizeof(DeletingLeaf482ab0) == 8, "minimal virtual interface size");
