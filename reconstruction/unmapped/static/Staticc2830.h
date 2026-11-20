// Source exposure: binary-analysis
// Staticc2830, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc2830;
extern void construct(Staticc2830*, const Descriptor*);
extern void destroy(Staticc2830*);
struct Staticc2830 {
    void* value;
    Staticc2830() { construct(this, &descriptor); }
    ~Staticc2830() { destroy(this); }
};
