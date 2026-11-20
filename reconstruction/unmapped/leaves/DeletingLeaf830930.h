// Source exposure: binary-analysis
// DeletingLeaf830930, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf830930 {
public:
    virtual ~DeletingLeaf830930() {}
};
static_assert(sizeof(DeletingLeaf830930) == 8, "minimal virtual interface size");
