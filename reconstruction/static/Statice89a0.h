// Source exposure: binary-analysis
// Statice89a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice89a0;
extern void construct(Statice89a0*, const Descriptor*);
extern void destroy(Statice89a0*);
struct Statice89a0 {
    void* value;
    Statice89a0() { construct(this, &descriptor); }
    ~Statice89a0() { destroy(this); }
};
