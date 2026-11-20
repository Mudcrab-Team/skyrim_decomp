// Source exposure: binary-analysis
// DeletingLeaf838a00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf838a00 {
public:
    virtual ~DeletingLeaf838a00() {}
};
static_assert(sizeof(DeletingLeaf838a00) == 8, "minimal virtual interface size");
