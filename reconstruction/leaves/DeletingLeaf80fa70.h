// Source exposure: binary-analysis
// DeletingLeaf80fa70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf80fa70 {
public:
    virtual ~DeletingLeaf80fa70() {}
};
static_assert(sizeof(DeletingLeaf80fa70) == 8, "minimal virtual interface size");
