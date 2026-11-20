// Source exposure: binary-analysis
// DeletingLeaf121d950, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121d950 {
public:
    virtual ~DeletingLeaf121d950() {}
};
static_assert(sizeof(DeletingLeaf121d950) == 8, "minimal virtual interface size");
