// Source exposure: binary-analysis
// DeletingLeaf66db90, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66db90 {
public:
    virtual ~DeletingLeaf66db90() {}
};
static_assert(sizeof(DeletingLeaf66db90) == 8, "minimal virtual interface size");
