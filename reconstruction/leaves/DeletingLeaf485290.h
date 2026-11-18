// Source exposure: binary-analysis
// DeletingLeaf485290, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf485290 {
public:
    virtual ~DeletingLeaf485290() {}
};
static_assert(sizeof(DeletingLeaf485290) == 8, "minimal virtual interface size");
