// Source exposure: binary-analysis
// DeletingLeaf661b40, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf661b40 {
public:
    virtual ~DeletingLeaf661b40() {}
};
static_assert(sizeof(DeletingLeaf661b40) == 8, "minimal virtual interface size");
