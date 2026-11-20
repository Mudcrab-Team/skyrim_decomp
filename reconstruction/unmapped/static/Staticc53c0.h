// Source exposure: binary-analysis
// Staticc53c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc53c0;
extern void construct(Staticc53c0*, const Descriptor*);
extern void destroy(Staticc53c0*);
struct Staticc53c0 {
    void* value;
    Staticc53c0() { construct(this, &descriptor); }
    ~Staticc53c0() { destroy(this); }
};
