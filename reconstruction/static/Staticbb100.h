// Source exposure: binary-analysis
// Staticbb100, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbb100;
extern void construct(Staticbb100*, const Descriptor*);
extern void destroy(Staticbb100*);
struct Staticbb100 {
    void* value;
    Staticbb100() { construct(this, &descriptor); }
    ~Staticbb100() { destroy(this); }
};
