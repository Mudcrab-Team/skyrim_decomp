// Source exposure: binary-analysis
// Staticd360, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd360;
extern void construct(Staticd360*, const Descriptor*);
extern void destroy(Staticd360*);
struct Staticd360 {
    void* value;
    Staticd360() { construct(this, &descriptor); }
    ~Staticd360() { destroy(this); }
};
