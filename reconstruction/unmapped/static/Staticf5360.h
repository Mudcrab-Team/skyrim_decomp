// Source exposure: binary-analysis
// Staticf5360, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf5360;
extern void construct(Staticf5360*, const Descriptor*);
extern void destroy(Staticf5360*);
struct Staticf5360 {
    void* value;
    Staticf5360() { construct(this, &descriptor); }
    ~Staticf5360() { destroy(this); }
};
