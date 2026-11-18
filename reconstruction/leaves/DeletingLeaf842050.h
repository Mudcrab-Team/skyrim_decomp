// Source exposure: binary-analysis
// DeletingLeaf842050, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf842050 {
public:
    virtual ~DeletingLeaf842050() {}
};
static_assert(sizeof(DeletingLeaf842050) == 8, "minimal virtual interface size");
