// Source exposure: binary-analysis
// DeletingLeaf9f0020, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9f0020 {
public:
    virtual ~DeletingLeaf9f0020() {}
};
static_assert(sizeof(DeletingLeaf9f0020) == 8, "minimal virtual interface size");
