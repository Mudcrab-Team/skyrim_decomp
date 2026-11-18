// Source exposure: binary-analysis
// Staticc9bf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc9bf0;
extern void construct(Staticc9bf0*, const Descriptor*);
extern void destroy(Staticc9bf0*);
struct Staticc9bf0 {
    void* value;
    Staticc9bf0() { construct(this, &descriptor); }
    ~Staticc9bf0() { destroy(this); }
};
