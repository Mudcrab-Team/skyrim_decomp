// Source exposure: binary-analysis
// DeletingLeaf844030, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf844030 {
public:
    virtual ~DeletingLeaf844030() {}
};
static_assert(sizeof(DeletingLeaf844030) == 8, "minimal virtual interface size");
