// Source exposure: binary-analysis
// DeletingLeaf121b220, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121b220 {
public:
    virtual ~DeletingLeaf121b220() {}
};
static_assert(sizeof(DeletingLeaf121b220) == 8, "minimal virtual interface size");
