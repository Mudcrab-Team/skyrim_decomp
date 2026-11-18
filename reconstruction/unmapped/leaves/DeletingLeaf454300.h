// Source exposure: binary-analysis
// DeletingLeaf454300, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf454300 {
public:
    virtual ~DeletingLeaf454300() {}
};
static_assert(sizeof(DeletingLeaf454300) == 8, "minimal virtual interface size");
