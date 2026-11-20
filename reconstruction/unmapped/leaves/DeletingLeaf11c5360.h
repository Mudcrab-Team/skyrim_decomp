// Source exposure: binary-analysis
// DeletingLeaf11c5360, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf11c5360 {
public:
    virtual ~DeletingLeaf11c5360() {}
};
static_assert(sizeof(DeletingLeaf11c5360) == 8, "minimal virtual interface size");
