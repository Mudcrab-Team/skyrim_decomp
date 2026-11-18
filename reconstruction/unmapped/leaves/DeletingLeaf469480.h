// Source exposure: binary-analysis
// DeletingLeaf469480, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf469480 {
public:
    virtual ~DeletingLeaf469480() {}
};
static_assert(sizeof(DeletingLeaf469480) == 8, "minimal virtual interface size");
