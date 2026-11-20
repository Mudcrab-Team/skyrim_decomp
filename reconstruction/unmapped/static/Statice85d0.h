// Source exposure: binary-analysis
// Statice85d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice85d0;
extern void construct(Statice85d0*, const Descriptor*);
extern void destroy(Statice85d0*);
struct Statice85d0 {
    void* value;
    Statice85d0() { construct(this, &descriptor); }
    ~Statice85d0() { destroy(this); }
};
