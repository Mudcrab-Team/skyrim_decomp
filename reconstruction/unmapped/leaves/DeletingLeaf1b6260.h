// Source exposure: binary-analysis
// DeletingLeaf1b6260, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1b6260 {
public:
    virtual ~DeletingLeaf1b6260() {}
};
static_assert(sizeof(DeletingLeaf1b6260) == 8, "minimal virtual interface size");
