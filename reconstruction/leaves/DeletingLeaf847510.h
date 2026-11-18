// Source exposure: binary-analysis
// DeletingLeaf847510, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf847510 {
public:
    virtual ~DeletingLeaf847510() {}
};
static_assert(sizeof(DeletingLeaf847510) == 8, "minimal virtual interface size");
