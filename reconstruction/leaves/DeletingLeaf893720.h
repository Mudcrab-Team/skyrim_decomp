// Source exposure: binary-analysis
// DeletingLeaf893720, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf893720 {
public:
    virtual ~DeletingLeaf893720() {}
};
static_assert(sizeof(DeletingLeaf893720) == 8, "minimal virtual interface size");
