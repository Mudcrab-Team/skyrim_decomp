// Source exposure: binary-analysis
// Staticbafe0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbafe0;
extern void construct(Staticbafe0*, const Descriptor*);
extern void destroy(Staticbafe0*);
struct Staticbafe0 {
    void* value;
    Staticbafe0() { construct(this, &descriptor); }
    ~Staticbafe0() { destroy(this); }
};
