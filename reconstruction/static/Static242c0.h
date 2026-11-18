// Source exposure: binary-analysis
// Static242c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static242c0;
extern void construct(Static242c0*, const Descriptor*);
extern void destroy(Static242c0*);
struct Static242c0 {
    void* value;
    Static242c0() { construct(this, &descriptor); }
    ~Static242c0() { destroy(this); }
};
