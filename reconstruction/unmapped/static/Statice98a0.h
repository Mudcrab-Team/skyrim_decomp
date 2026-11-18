// Source exposure: binary-analysis
// Statice98a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice98a0;
extern void construct(Statice98a0*, const Descriptor*);
extern void destroy(Statice98a0*);
struct Statice98a0 {
    void* value;
    Statice98a0() { construct(this, &descriptor); }
    ~Statice98a0() { destroy(this); }
};
