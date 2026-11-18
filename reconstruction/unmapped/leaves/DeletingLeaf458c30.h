// Source exposure: binary-analysis
// DeletingLeaf458c30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458c30 {
public:
    virtual ~DeletingLeaf458c30() {}
};
static_assert(sizeof(DeletingLeaf458c30) == 8, "minimal virtual interface size");
