// Source exposure: binary-analysis
// Statice91f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice91f0;
extern void construct(Statice91f0*, const Descriptor*);
extern void destroy(Statice91f0*);
struct Statice91f0 {
    void* value;
    Statice91f0() { construct(this, &descriptor); }
    ~Statice91f0() { destroy(this); }
};
