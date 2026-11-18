// Source exposure: binary-analysis
// Static12bd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static12bd0;
extern void construct(Static12bd0*, const Descriptor*);
extern void destroy(Static12bd0*);
struct Static12bd0 {
    void* value;
    Static12bd0() { construct(this, &descriptor); }
    ~Static12bd0() { destroy(this); }
};
