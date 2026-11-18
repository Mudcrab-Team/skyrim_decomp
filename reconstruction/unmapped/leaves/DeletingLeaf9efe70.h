// Source exposure: binary-analysis
// DeletingLeaf9efe70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9efe70 {
public:
    virtual ~DeletingLeaf9efe70() {}
};
static_assert(sizeof(DeletingLeaf9efe70) == 8, "minimal virtual interface size");
