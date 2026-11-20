// Source exposure: binary-analysis
// Static158b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static158b0;
extern void construct(Static158b0*, const Descriptor*);
extern void destroy(Static158b0*);
struct Static158b0 {
    void* value;
    Static158b0() { construct(this, &descriptor); }
    ~Static158b0() { destroy(this); }
};
