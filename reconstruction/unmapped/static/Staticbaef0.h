// Source exposure: binary-analysis
// Staticbaef0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbaef0;
extern void construct(Staticbaef0*, const Descriptor*);
extern void destroy(Staticbaef0*);
struct Staticbaef0 {
    void* value;
    Staticbaef0() { construct(this, &descriptor); }
    ~Staticbaef0() { destroy(this); }
};
