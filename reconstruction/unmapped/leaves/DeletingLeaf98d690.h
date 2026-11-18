// Source exposure: binary-analysis
// DeletingLeaf98d690, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf98d690 {
public:
    virtual ~DeletingLeaf98d690() {}
};
static_assert(sizeof(DeletingLeaf98d690) == 8, "minimal virtual interface size");
