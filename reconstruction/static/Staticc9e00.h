// Source exposure: binary-analysis
// Staticc9e00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc9e00;
extern void construct(Staticc9e00*, const Descriptor*);
extern void destroy(Staticc9e00*);
struct Staticc9e00 {
    void* value;
    Staticc9e00() { construct(this, &descriptor); }
    ~Staticc9e00() { destroy(this); }
};
