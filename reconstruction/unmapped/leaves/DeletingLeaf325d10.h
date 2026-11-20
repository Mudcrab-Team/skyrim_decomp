// Source exposure: binary-analysis
// DeletingLeaf325d10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf325d10 {
public:
    virtual ~DeletingLeaf325d10() {}
};
static_assert(sizeof(DeletingLeaf325d10) == 8, "minimal virtual interface size");
