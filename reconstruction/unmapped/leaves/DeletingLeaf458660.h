// Source exposure: binary-analysis
// DeletingLeaf458660, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458660 {
public:
    virtual ~DeletingLeaf458660() {}
};
static_assert(sizeof(DeletingLeaf458660) == 8, "minimal virtual interface size");
