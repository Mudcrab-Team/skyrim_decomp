// Source exposure: binary-analysis
// Staticef8b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticef8b0;
extern void construct(Staticef8b0*, const Descriptor*);
extern void destroy(Staticef8b0*);
struct Staticef8b0 {
    void* value;
    Staticef8b0() { construct(this, &descriptor); }
    ~Staticef8b0() { destroy(this); }
};
