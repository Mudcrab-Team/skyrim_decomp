// Source exposure: binary-analysis
// DeletingLeaf27acd0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf27acd0 {
public:
    virtual ~DeletingLeaf27acd0() {}
};
static_assert(sizeof(DeletingLeaf27acd0) == 8, "minimal virtual interface size");
