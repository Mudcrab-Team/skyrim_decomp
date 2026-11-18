// Source exposure: binary-analysis
// DeletingLeaf121b770, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121b770 {
public:
    virtual ~DeletingLeaf121b770() {}
};
static_assert(sizeof(DeletingLeaf121b770) == 8, "minimal virtual interface size");
