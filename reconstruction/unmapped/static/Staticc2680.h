// Source exposure: binary-analysis
// Staticc2680, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc2680;
extern void construct(Staticc2680*, const Descriptor*);
extern void destroy(Staticc2680*);
struct Staticc2680 {
    void* value;
    Staticc2680() { construct(this, &descriptor); }
    ~Staticc2680() { destroy(this); }
};
