// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSTaskletManager: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionec3aa0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// TaskEc3aa0: GUESS(low) STANDIN; tasklet interface and cancellation state
struct TaskEc3aa0 { virtual ~TaskEc3aa0(); virtual void Run(bool); virtual void Prepare(); unsigned char cancelled; };

class BSTaskletManager
{
public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void Unk06();
    virtual void Unk07();
    virtual void Submit(TaskEc3aa0*);

    void Functionec3aa0(TaskEc3aa0*& task, bool mode);
};
