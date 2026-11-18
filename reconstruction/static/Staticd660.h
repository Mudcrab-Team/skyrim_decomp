// Source exposure: binary-analysis
// Staticd660, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd660;
extern void construct(Staticd660*, const Descriptor*);
extern void destroy(Staticd660*);
struct Staticd660 {
    void* value;
    Staticd660() { construct(this, &descriptor); }
    ~Staticd660() { destroy(this); }
};
