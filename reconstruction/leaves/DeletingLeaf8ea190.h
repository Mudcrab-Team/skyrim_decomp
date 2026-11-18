// Source exposure: binary-analysis
// DeletingLeaf8ea190, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf8ea190 {
public:
    virtual ~DeletingLeaf8ea190() {}
};
static_assert(sizeof(DeletingLeaf8ea190) == 8, "minimal virtual interface size");
