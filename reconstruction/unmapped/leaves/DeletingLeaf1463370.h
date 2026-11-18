// Source exposure: binary-analysis
// DeletingLeaf1463370, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1463370 {
public:
    virtual ~DeletingLeaf1463370() {}
};
static_assert(sizeof(DeletingLeaf1463370) == 8, "minimal virtual interface size");
