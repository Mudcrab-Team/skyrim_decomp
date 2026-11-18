// Source exposure: binary-analysis
// DeletingLeaf454890, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf454890 {
public:
    virtual ~DeletingLeaf454890() {}
};
static_assert(sizeof(DeletingLeaf454890) == 8, "minimal virtual interface size");
