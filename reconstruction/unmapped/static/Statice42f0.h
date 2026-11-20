// Source exposure: binary-analysis
// Statice42f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice42f0;
extern void construct(Statice42f0*, const Descriptor*);
extern void destroy(Statice42f0*);
struct Statice42f0 {
    void* value;
    Statice42f0() { construct(this, &descriptor); }
    ~Statice42f0() { destroy(this); }
};
