// Source exposure: binary-analysis
// Staticb7360, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7360;
extern void construct(Staticb7360*, const Descriptor*);
extern void destroy(Staticb7360*);
struct Staticb7360 {
    void* value;
    Staticb7360() { construct(this, &descriptor); }
    ~Staticb7360() { destroy(this); }
};
