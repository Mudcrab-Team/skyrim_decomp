// Source exposure: binary-analysis
// Staticd900, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd900;
extern void construct(Staticd900*, const Descriptor*);
extern void destroy(Staticd900*);
struct Staticd900 {
    void* value;
    Staticd900() { construct(this, &descriptor); }
    ~Staticd900() { destroy(this); }
};
