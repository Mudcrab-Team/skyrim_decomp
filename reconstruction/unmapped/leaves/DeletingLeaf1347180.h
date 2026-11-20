// Source exposure: binary-analysis
// DeletingLeaf1347180, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1347180 {
public:
    virtual ~DeletingLeaf1347180() {}
};
static_assert(sizeof(DeletingLeaf1347180) == 8, "minimal virtual interface size");
