// Source exposure: binary-analysis
// DeletingWrapper1e7870, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper1e7870 {
public:
    virtual ~DeletingWrapper1e7870();
};
static_assert(sizeof(DeletingWrapper1e7870) == 8, "interface layout");
