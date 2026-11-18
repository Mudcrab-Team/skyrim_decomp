// Source exposure: binary-analysis
// DeletingLeaf121d8f0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121d8f0 {
public:
    virtual ~DeletingLeaf121d8f0() {}
};
static_assert(sizeof(DeletingLeaf121d8f0) == 8, "minimal virtual interface size");
