// Source exposure: binary-analysis
// DeletingLeaf489ed0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf489ed0 {
public:
    virtual ~DeletingLeaf489ed0() {}
};
static_assert(sizeof(DeletingLeaf489ed0) == 8, "minimal virtual interface size");
