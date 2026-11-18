// Source exposure: binary-analysis
// DeletingLeaf458480, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf458480 {
public:
    virtual ~DeletingLeaf458480() {}
};
static_assert(sizeof(DeletingLeaf458480) == 8, "minimal virtual interface size");
