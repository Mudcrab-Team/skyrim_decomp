// Source exposure: binary-analysis
// Staticb5610, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5610;
extern void construct(Staticb5610*, const Descriptor*);
extern void destroy(Staticb5610*);
struct Staticb5610 {
    void* value;
    Staticb5610() { construct(this, &descriptor); }
    ~Staticb5610() { destroy(this); }
};
