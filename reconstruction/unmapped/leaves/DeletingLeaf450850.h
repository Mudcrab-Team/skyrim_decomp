// Source exposure: binary-analysis
// DeletingLeaf450850, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf450850 {
public:
    virtual ~DeletingLeaf450850() {}
};
static_assert(sizeof(DeletingLeaf450850) == 8, "minimal virtual interface size");
