// Source exposure: binary-analysis
// Staticb4190, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb4190;
extern void construct(Staticb4190*, const Descriptor*);
extern void destroy(Staticb4190*);
struct Staticb4190 {
    void* value;
    Staticb4190() { construct(this, &descriptor); }
    ~Staticb4190() { destroy(this); }
};
