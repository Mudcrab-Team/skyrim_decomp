// Source exposure: binary-analysis
// DeletingLeaf80ff80, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf80ff80 {
public:
    virtual ~DeletingLeaf80ff80() {}
};
static_assert(sizeof(DeletingLeaf80ff80) == 8, "minimal virtual interface size");
