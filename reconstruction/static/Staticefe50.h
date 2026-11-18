// Source exposure: binary-analysis
// Staticefe50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticefe50;
extern void construct(Staticefe50*, const Descriptor*);
extern void destroy(Staticefe50*);
struct Staticefe50 {
    void* value;
    Staticefe50() { construct(this, &descriptor); }
    ~Staticefe50() { destroy(this); }
};
