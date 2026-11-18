// Source exposure: binary-analysis
// DeletingLeaf1139320, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1139320 {
public:
    virtual ~DeletingLeaf1139320() {}
};
static_assert(sizeof(DeletingLeaf1139320) == 8, "minimal virtual interface size");
