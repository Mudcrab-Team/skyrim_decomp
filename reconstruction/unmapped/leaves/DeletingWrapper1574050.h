// Source exposure: binary-analysis
// DeletingWrapper1574050, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper1574050 {
public:
    virtual ~DeletingWrapper1574050();
};
static_assert(sizeof(DeletingWrapper1574050) == 8, "interface layout");
