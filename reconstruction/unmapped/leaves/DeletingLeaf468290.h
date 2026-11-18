// Source exposure: binary-analysis
// DeletingLeaf468290, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf468290 {
public:
    virtual ~DeletingLeaf468290() {}
};
static_assert(sizeof(DeletingLeaf468290) == 8, "minimal virtual interface size");
