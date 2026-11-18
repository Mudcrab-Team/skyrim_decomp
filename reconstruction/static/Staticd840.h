// Source exposure: binary-analysis
// Staticd840, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd840;
extern void construct(Staticd840*, const Descriptor*);
extern void destroy(Staticd840*);
struct Staticd840 {
    void* value;
    Staticd840() { construct(this, &descriptor); }
    ~Staticd840() { destroy(this); }
};
