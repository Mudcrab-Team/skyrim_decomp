// Source exposure: binary-analysis
// DeletingLeaf121b280, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121b280 {
public:
    virtual ~DeletingLeaf121b280() {}
};
static_assert(sizeof(DeletingLeaf121b280) == 8, "minimal virtual interface size");
