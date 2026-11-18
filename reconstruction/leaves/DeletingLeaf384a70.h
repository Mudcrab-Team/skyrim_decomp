// Source exposure: binary-analysis
// DeletingLeaf384a70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf384a70 {
public:
    virtual ~DeletingLeaf384a70() {}
};
static_assert(sizeof(DeletingLeaf384a70) == 8, "minimal virtual interface size");
