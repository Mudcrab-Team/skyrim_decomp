// Source exposure: binary-analysis
// Staticc1670, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc1670;
extern void construct(Staticc1670*, const Descriptor*);
extern void destroy(Staticc1670*);
struct Staticc1670 {
    void* value;
    Staticc1670() { construct(this, &descriptor); }
    ~Staticc1670() { destroy(this); }
};
