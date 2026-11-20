// Source exposure: binary-analysis
// DeletingWrapper6e1b10, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper6e1b10 {
public:
    virtual ~DeletingWrapper6e1b10();
};
static_assert(sizeof(DeletingWrapper6e1b10) == 8, "interface layout");
