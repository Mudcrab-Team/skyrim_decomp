// Source exposure: binary-analysis
// DeletingLeaf49ec20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf49ec20 {
public:
    virtual ~DeletingLeaf49ec20() {}
};
static_assert(sizeof(DeletingLeaf49ec20) == 8, "minimal virtual interface size");
