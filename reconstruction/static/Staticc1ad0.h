// Source exposure: binary-analysis
// Staticc1ad0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc1ad0;
extern void construct(Staticc1ad0*, const Descriptor*);
extern void destroy(Staticc1ad0*);
struct Staticc1ad0 {
    void* value;
    Staticc1ad0() { construct(this, &descriptor); }
    ~Staticc1ad0() { destroy(this); }
};
