// Source exposure: binary-analysis
// DeletingLeaf6c7360, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf6c7360 {
public:
    virtual ~DeletingLeaf6c7360() {}
};
static_assert(sizeof(DeletingLeaf6c7360) == 8, "minimal virtual interface size");
