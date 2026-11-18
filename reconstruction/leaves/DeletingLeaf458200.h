// Source exposure: binary-analysis
// DeletingLeaf458200, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458200 {
public:
    virtual ~DeletingLeaf458200() {}
};
static_assert(sizeof(DeletingLeaf458200) == 8, "minimal virtual interface size");
