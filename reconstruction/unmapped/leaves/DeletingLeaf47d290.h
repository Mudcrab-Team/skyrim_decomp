// Source exposure: binary-analysis
// DeletingLeaf47d290, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf47d290 {
public:
    virtual ~DeletingLeaf47d290() {}
};
static_assert(sizeof(DeletingLeaf47d290) == 8, "minimal virtual interface size");
