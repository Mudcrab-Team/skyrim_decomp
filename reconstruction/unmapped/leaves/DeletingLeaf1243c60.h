// Source exposure: binary-analysis
// DeletingLeaf1243c60, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1243c60 {
public:
    virtual ~DeletingLeaf1243c60() {}
};
static_assert(sizeof(DeletingLeaf1243c60) == 8, "minimal virtual interface size");
