// Source exposure: binary-analysis
// DeletingLeaf45cee0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf45cee0 {
public:
    virtual ~DeletingLeaf45cee0() {}
};
static_assert(sizeof(DeletingLeaf45cee0) == 8, "minimal virtual interface size");
