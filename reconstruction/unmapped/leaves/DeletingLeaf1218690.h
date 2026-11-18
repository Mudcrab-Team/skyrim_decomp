// Source exposure: binary-analysis
// DeletingLeaf1218690, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1218690 {
public:
    virtual ~DeletingLeaf1218690() {}
};
static_assert(sizeof(DeletingLeaf1218690) == 8, "minimal virtual interface size");
