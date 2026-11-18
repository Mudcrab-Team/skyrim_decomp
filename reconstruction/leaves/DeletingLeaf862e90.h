// Source exposure: binary-analysis
// DeletingLeaf862e90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf862e90 {
public:
    virtual ~DeletingLeaf862e90() {}
};
static_assert(sizeof(DeletingLeaf862e90) == 8, "minimal virtual interface size");
