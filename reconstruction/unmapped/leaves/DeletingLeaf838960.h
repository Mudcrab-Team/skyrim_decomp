// Source exposure: binary-analysis
// DeletingLeaf838960, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf838960 {
public:
    virtual ~DeletingLeaf838960() {}
};
static_assert(sizeof(DeletingLeaf838960) == 8, "minimal virtual interface size");
