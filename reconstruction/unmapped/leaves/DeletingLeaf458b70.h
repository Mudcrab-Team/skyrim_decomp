// Source exposure: binary-analysis
// DeletingLeaf458b70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458b70 {
public:
    virtual ~DeletingLeaf458b70() {}
};
static_assert(sizeof(DeletingLeaf458b70) == 8, "minimal virtual interface size");
