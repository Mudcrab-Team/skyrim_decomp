// Source exposure: binary-analysis
// DeletingLeaf840720, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf840720 {
public:
    virtual ~DeletingLeaf840720() {}
};
static_assert(sizeof(DeletingLeaf840720) == 8, "minimal virtual interface size");
