// Source exposure: binary-analysis
// DeletingLeaf1151560, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1151560 {
public:
    virtual ~DeletingLeaf1151560() {}
};
static_assert(sizeof(DeletingLeaf1151560) == 8, "minimal virtual interface size");
