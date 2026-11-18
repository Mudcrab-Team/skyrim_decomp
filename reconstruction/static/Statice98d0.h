// Source exposure: binary-analysis
// Statice98d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice98d0;
extern void construct(Statice98d0*, const Descriptor*);
extern void destroy(Statice98d0*);
struct Statice98d0 {
    void* value;
    Statice98d0() { construct(this, &descriptor); }
    ~Statice98d0() { destroy(this); }
};
