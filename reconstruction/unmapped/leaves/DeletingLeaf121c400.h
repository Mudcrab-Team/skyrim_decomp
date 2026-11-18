// Source exposure: binary-analysis
// DeletingLeaf121c400, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121c400 {
public:
    virtual ~DeletingLeaf121c400() {}
};
static_assert(sizeof(DeletingLeaf121c400) == 8, "minimal virtual interface size");
