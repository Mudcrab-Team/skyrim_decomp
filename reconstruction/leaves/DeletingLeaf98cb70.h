// Source exposure: binary-analysis
// DeletingLeaf98cb70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf98cb70 {
public:
    virtual ~DeletingLeaf98cb70() {}
};
static_assert(sizeof(DeletingLeaf98cb70) == 8, "minimal virtual interface size");
