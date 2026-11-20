// Source exposure: binary-analysis
// Staticefe20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticefe20;
extern void construct(Staticefe20*, const Descriptor*);
extern void destroy(Staticefe20*);
struct Staticefe20 {
    void* value;
    Staticefe20() { construct(this, &descriptor); }
    ~Staticefe20() { destroy(this); }
};
