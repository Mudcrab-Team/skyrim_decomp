// Source exposure: binary-analysis
// DeletingLeaf485260, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf485260 {
public:
    virtual ~DeletingLeaf485260() {}
};
static_assert(sizeof(DeletingLeaf485260) == 8, "minimal virtual interface size");
