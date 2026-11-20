// Source exposure: binary-analysis
// Staticbb070, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbb070;
extern void construct(Staticbb070*, const Descriptor*);
extern void destroy(Staticbb070*);
struct Staticbb070 {
    void* value;
    Staticbb070() { construct(this, &descriptor); }
    ~Staticbb070() { destroy(this); }
};
