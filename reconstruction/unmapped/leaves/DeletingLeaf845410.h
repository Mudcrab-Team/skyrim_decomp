// Source exposure: binary-analysis
// DeletingLeaf845410, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf845410 {
public:
    virtual ~DeletingLeaf845410() {}
};
static_assert(sizeof(DeletingLeaf845410) == 8, "minimal virtual interface size");
