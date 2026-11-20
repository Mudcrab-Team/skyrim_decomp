// Source exposure: binary-analysis
// Static975a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static975a0;
extern void construct(Static975a0*, const Descriptor*);
extern void destroy(Static975a0*);
struct Static975a0 {
    void* value;
    Static975a0() { construct(this, &descriptor); }
    ~Static975a0() { destroy(this); }
};
