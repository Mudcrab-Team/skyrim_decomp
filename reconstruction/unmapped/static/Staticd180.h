// Source exposure: binary-analysis
// Staticd180, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticd180;
extern void construct(Staticd180*, const Descriptor*);
extern void destroy(Staticd180*);
struct Staticd180 {
    void* value;
    Staticd180() { construct(this, &descriptor); }
    ~Staticd180() { destroy(this); }
};
