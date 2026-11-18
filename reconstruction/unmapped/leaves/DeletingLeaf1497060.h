// Source exposure: binary-analysis
// DeletingLeaf1497060, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1497060 {
public:
    virtual ~DeletingLeaf1497060() {}
};
static_assert(sizeof(DeletingLeaf1497060) == 8, "minimal virtual interface size");
