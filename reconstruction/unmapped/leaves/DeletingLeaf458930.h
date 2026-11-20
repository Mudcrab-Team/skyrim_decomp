// Source exposure: binary-analysis
// DeletingLeaf458930, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458930 {
public:
    virtual ~DeletingLeaf458930() {}
};
static_assert(sizeof(DeletingLeaf458930) == 8, "minimal virtual interface size");
