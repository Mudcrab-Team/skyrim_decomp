// Source exposure: binary-analysis
// DeletingLeaf845d10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf845d10 {
public:
    virtual ~DeletingLeaf845d10() {}
};
static_assert(sizeof(DeletingLeaf845d10) == 8, "minimal virtual interface size");
