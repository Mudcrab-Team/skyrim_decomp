// Source exposure: binary-analysis
// Staticda50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticda50;
extern void construct(Staticda50*, const Descriptor*);
extern void destroy(Staticda50*);
struct Staticda50 {
    void* value;
    Staticda50() { construct(this, &descriptor); }
    ~Staticda50() { destroy(this); }
};
