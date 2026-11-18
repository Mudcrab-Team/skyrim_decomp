// Source exposure: binary-analysis
// DeletingWrapper1172420, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper1172420 {
public:
    virtual ~DeletingWrapper1172420();
};
static_assert(sizeof(DeletingWrapper1172420) == 8, "interface layout");
