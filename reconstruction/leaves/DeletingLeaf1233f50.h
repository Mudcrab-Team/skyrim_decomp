// Source exposure: binary-analysis
// DeletingLeaf1233f50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1233f50 {
public:
    virtual ~DeletingLeaf1233f50() {}
};
static_assert(sizeof(DeletingLeaf1233f50) == 8, "minimal virtual interface size");
