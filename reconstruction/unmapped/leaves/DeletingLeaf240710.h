// Source exposure: binary-analysis
// DeletingLeaf240710, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf240710 {
public:
    virtual ~DeletingLeaf240710() {}
};
static_assert(sizeof(DeletingLeaf240710) == 8, "minimal virtual interface size");
