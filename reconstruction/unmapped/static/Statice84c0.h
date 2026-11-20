// Source exposure: binary-analysis
// Statice84c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice84c0;
extern void construct(Statice84c0*, const Descriptor*);
extern void destroy(Statice84c0*);
struct Statice84c0 {
    void* value;
    Statice84c0() { construct(this, &descriptor); }
    ~Statice84c0() { destroy(this); }
};
