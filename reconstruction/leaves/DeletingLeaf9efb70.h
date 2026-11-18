// Source exposure: binary-analysis
// DeletingLeaf9efb70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf9efb70 {
public:
    virtual ~DeletingLeaf9efb70() {}
};
static_assert(sizeof(DeletingLeaf9efb70) == 8, "minimal virtual interface size");
