// Source exposure: binary-analysis
// DeletingLeafdf8190, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafdf8190 {
public:
    virtual ~DeletingLeafdf8190() {}
};
static_assert(sizeof(DeletingLeafdf8190) == 8, "minimal virtual interface size");
