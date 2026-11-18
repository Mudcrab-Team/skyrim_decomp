// Source exposure: binary-analysis
// DeletingLeaf863500, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf863500 {
public:
    virtual ~DeletingLeaf863500() {}
};
static_assert(sizeof(DeletingLeaf863500) == 8, "minimal virtual interface size");
