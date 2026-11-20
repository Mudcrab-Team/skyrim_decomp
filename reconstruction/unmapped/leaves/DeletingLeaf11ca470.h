// Source exposure: binary-analysis
// DeletingLeaf11ca470, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf11ca470 {
public:
    virtual ~DeletingLeaf11ca470() {}
};
static_assert(sizeof(DeletingLeaf11ca470) == 8, "minimal virtual interface size");
