// Source exposure: binary-analysis
// DeletingLeaf122ca40, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf122ca40 {
public:
    virtual ~DeletingLeaf122ca40() {}
};
static_assert(sizeof(DeletingLeaf122ca40) == 8, "minimal virtual interface size");
