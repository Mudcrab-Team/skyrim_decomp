// Source exposure: binary-analysis
// DeletingLeaf98d190, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf98d190 {
public:
    virtual ~DeletingLeaf98d190() {}
};
static_assert(sizeof(DeletingLeaf98d190) == 8, "minimal virtual interface size");
