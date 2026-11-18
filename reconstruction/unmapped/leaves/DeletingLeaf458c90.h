// Source exposure: binary-analysis
// DeletingLeaf458c90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458c90 {
public:
    virtual ~DeletingLeaf458c90() {}
};
static_assert(sizeof(DeletingLeaf458c90) == 8, "minimal virtual interface size");
