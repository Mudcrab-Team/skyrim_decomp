// Source exposure: binary-analysis
// DeletingLeaf152b560, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf152b560 {
public:
    virtual ~DeletingLeaf152b560() {}
};
static_assert(sizeof(DeletingLeaf152b560) == 8, "minimal virtual interface size");
