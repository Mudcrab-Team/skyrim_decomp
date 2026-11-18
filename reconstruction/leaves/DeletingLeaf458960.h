// Source exposure: binary-analysis
// DeletingLeaf458960, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458960 {
public:
    virtual ~DeletingLeaf458960() {}
};
static_assert(sizeof(DeletingLeaf458960) == 8, "minimal virtual interface size");
