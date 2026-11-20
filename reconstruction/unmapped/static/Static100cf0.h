// Source exposure: binary-analysis
// Static100cf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static100cf0;
extern void construct(Static100cf0*, const Descriptor*);
extern void destroy(Static100cf0*);
struct Static100cf0 {
    void* value;
    Static100cf0() { construct(this, &descriptor); }
    ~Static100cf0() { destroy(this); }
};
