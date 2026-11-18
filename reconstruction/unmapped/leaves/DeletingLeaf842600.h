// Source exposure: binary-analysis
// DeletingLeaf842600, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf842600 {
public:
    virtual ~DeletingLeaf842600() {}
};
static_assert(sizeof(DeletingLeaf842600) == 8, "minimal virtual interface size");
