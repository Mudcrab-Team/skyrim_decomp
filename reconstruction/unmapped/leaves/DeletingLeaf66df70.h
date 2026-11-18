// Source exposure: binary-analysis
// DeletingLeaf66df70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf66df70 {
public:
    virtual ~DeletingLeaf66df70() {}
};
static_assert(sizeof(DeletingLeaf66df70) == 8, "minimal virtual interface size");
