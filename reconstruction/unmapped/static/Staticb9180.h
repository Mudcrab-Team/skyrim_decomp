// Source exposure: binary-analysis
// Staticb9180, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9180;
extern void construct(Staticb9180*, const Descriptor*);
extern void destroy(Staticb9180*);
struct Staticb9180 {
    void* value;
    Staticb9180() { construct(this, &descriptor); }
    ~Staticb9180() { destroy(this); }
};
