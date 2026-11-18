// Source exposure: binary-analysis
// DeletingLeaf1095a70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1095a70 {
public:
    virtual ~DeletingLeaf1095a70() {}
};
static_assert(sizeof(DeletingLeaf1095a70) == 8, "minimal virtual interface size");
