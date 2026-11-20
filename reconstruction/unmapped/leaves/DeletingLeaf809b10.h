// Source exposure: binary-analysis
// DeletingLeaf809b10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf809b10 {
public:
    virtual ~DeletingLeaf809b10() {}
};
static_assert(sizeof(DeletingLeaf809b10) == 8, "minimal virtual interface size");
