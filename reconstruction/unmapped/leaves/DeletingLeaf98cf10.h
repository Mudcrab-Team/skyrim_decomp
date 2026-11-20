// Source exposure: binary-analysis
// DeletingLeaf98cf10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf98cf10 {
public:
    virtual ~DeletingLeaf98cf10() {}
};
static_assert(sizeof(DeletingLeaf98cf10) == 8, "minimal virtual interface size");
