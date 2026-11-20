// Source exposure: binary-analysis
// DeletingLeaf98d040, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf98d040 {
public:
    virtual ~DeletingLeaf98d040() {}
};
static_assert(sizeof(DeletingLeaf98d040) == 8, "minimal virtual interface size");
