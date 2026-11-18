// Source exposure: binary-analysis
// DeletingLeaf8ea160, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8ea160 {
public:
    virtual ~DeletingLeaf8ea160() {}
};
static_assert(sizeof(DeletingLeaf8ea160) == 8, "minimal virtual interface size");
