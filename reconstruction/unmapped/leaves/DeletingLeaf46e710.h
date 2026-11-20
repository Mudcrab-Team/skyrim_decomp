// Source exposure: binary-analysis
// DeletingLeaf46e710, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf46e710 {
public:
    virtual ~DeletingLeaf46e710() {}
};
static_assert(sizeof(DeletingLeaf46e710) == 8, "minimal virtual interface size");
