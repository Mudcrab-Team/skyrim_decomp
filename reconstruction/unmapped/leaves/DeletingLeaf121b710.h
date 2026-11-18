// Source exposure: binary-analysis
// DeletingLeaf121b710, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121b710 {
public:
    virtual ~DeletingLeaf121b710() {}
};
static_assert(sizeof(DeletingLeaf121b710) == 8, "minimal virtual interface size");
