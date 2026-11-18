// Source exposure: binary-analysis
// DeletingLeaf82ff20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf82ff20 {
public:
    virtual ~DeletingLeaf82ff20() {}
};
static_assert(sizeof(DeletingLeaf82ff20) == 8, "minimal virtual interface size");
