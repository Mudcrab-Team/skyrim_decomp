// Source exposure: binary-analysis
// DeletingLeaf830050, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830050 {
public:
    virtual ~DeletingLeaf830050() {}
};
static_assert(sizeof(DeletingLeaf830050) == 8, "minimal virtual interface size");
