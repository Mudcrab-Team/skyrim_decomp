// Source exposure: binary-analysis
// Staticb5190, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5190;
extern void construct(Staticb5190*, const Descriptor*);
extern void destroy(Staticb5190*);
struct Staticb5190 {
    void* value;
    Staticb5190() { construct(this, &descriptor); }
    ~Staticb5190() { destroy(this); }
};
