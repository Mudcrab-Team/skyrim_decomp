// Source exposure: binary-analysis
// DeletingLeaf458990, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458990 {
public:
    virtual ~DeletingLeaf458990() {}
};
static_assert(sizeof(DeletingLeaf458990) == 8, "minimal virtual interface size");
