// Source exposure: binary-analysis
// DeletingLeaf454330, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf454330 {
public:
    virtual ~DeletingLeaf454330() {}
};
static_assert(sizeof(DeletingLeaf454330) == 8, "minimal virtual interface size");
