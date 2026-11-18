// Source exposure: binary-analysis
// Statice7fe0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice7fe0;
extern void construct(Statice7fe0*, const Descriptor*);
extern void destroy(Statice7fe0*);
struct Statice7fe0 {
    void* value;
    Statice7fe0() { construct(this, &descriptor); }
    ~Statice7fe0() { destroy(this); }
};
