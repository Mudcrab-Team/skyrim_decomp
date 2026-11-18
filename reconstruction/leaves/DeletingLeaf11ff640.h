// Source exposure: binary-analysis
// DeletingLeaf11ff640, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf11ff640 {
public:
    virtual ~DeletingLeaf11ff640() {}
};
static_assert(sizeof(DeletingLeaf11ff640) == 8, "minimal virtual interface size");
