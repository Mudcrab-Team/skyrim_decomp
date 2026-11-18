// Source exposure: binary-analysis
// DeletingLeaf483640, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf483640 {
public:
    virtual ~DeletingLeaf483640() {}
};
static_assert(sizeof(DeletingLeaf483640) == 8, "minimal virtual interface size");
