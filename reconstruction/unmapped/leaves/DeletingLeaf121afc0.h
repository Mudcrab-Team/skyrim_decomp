// Source exposure: binary-analysis
// DeletingLeaf121afc0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121afc0 {
public:
    virtual ~DeletingLeaf121afc0() {}
};
static_assert(sizeof(DeletingLeaf121afc0) == 8, "minimal virtual interface size");
