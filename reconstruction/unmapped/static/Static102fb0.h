// Source exposure: binary-analysis
// Static102fb0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static102fb0;
extern void construct(Static102fb0*, const Descriptor*);
extern void destroy(Static102fb0*);
struct Static102fb0 {
    void* value;
    Static102fb0() { construct(this, &descriptor); }
    ~Static102fb0() { destroy(this); }
};
