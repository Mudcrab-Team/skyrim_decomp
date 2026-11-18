// Source exposure: binary-analysis
// DeletingLeaf117b240, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf117b240 {
public:
    virtual ~DeletingLeaf117b240() {}
};
static_assert(sizeof(DeletingLeaf117b240) == 8, "minimal virtual interface size");
