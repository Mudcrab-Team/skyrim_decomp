// Source exposure: binary-analysis
// DeletingLeaf458080, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458080 {
public:
    virtual ~DeletingLeaf458080() {}
};
static_assert(sizeof(DeletingLeaf458080) == 8, "minimal virtual interface size");
