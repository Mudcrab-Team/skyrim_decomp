// Source exposure: binary-analysis
// DeletingLeaf121a760, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf121a760 {
public:
    virtual ~DeletingLeaf121a760() {}
};
static_assert(sizeof(DeletingLeaf121a760) == 8, "minimal virtual interface size");
