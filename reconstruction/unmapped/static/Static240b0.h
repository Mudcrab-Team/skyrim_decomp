// Source exposure: binary-analysis
// Static240b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static240b0;
extern void construct(Static240b0*, const Descriptor*);
extern void destroy(Static240b0*);
struct Static240b0 {
    void* value;
    Static240b0() { construct(this, &descriptor); }
    ~Static240b0() { destroy(this); }
};
