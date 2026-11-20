// Source exposure: binary-analysis
// DeletingLeaf93bbd0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf93bbd0 {
public:
    virtual ~DeletingLeaf93bbd0() {}
};
static_assert(sizeof(DeletingLeaf93bbd0) == 8, "minimal virtual interface size");
