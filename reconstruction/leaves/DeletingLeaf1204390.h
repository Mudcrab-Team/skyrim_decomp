// Source exposure: binary-analysis
// DeletingLeaf1204390, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1204390 {
public:
    virtual ~DeletingLeaf1204390() {}
};
static_assert(sizeof(DeletingLeaf1204390) == 8, "minimal virtual interface size");
