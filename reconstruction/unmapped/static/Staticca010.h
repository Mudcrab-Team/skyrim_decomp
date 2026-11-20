// Source exposure: binary-analysis
// Staticca010, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca010;
extern void construct(Staticca010*, const Descriptor*);
extern void destroy(Staticca010*);
struct Staticca010 {
    void* value;
    Staticca010() { construct(this, &descriptor); }
    ~Staticca010() { destroy(this); }
};
