// Source exposure: binary-analysis
// Statice94a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice94a0;
extern void construct(Statice94a0*, const Descriptor*);
extern void destroy(Statice94a0*);
struct Statice94a0 {
    void* value;
    Statice94a0() { construct(this, &descriptor); }
    ~Statice94a0() { destroy(this); }
};
