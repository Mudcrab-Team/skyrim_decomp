// Source exposure: binary-analysis
// DeletingWrapper384d40, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper384d40 {
public:
    virtual ~DeletingWrapper384d40();
};
static_assert(sizeof(DeletingWrapper384d40) == 8, "interface layout");
