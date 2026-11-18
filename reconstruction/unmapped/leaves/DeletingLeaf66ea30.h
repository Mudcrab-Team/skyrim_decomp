// Source exposure: binary-analysis
// DeletingLeaf66ea30, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66ea30 {
public:
    virtual ~DeletingLeaf66ea30() {}
};
static_assert(sizeof(DeletingLeaf66ea30) == 8, "minimal virtual interface size");
