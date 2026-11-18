// Source exposure: binary-analysis
// Statice88e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statice88e0;
extern void construct(Statice88e0*, const Descriptor*);
extern void destroy(Statice88e0*);
struct Statice88e0 {
    void* value;
    Statice88e0() { construct(this, &descriptor); }
    ~Statice88e0() { destroy(this); }
};
