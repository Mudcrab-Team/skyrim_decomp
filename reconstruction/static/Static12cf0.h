// Source exposure: binary-analysis
// Static12cf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static12cf0;
extern void construct(Static12cf0*, const Descriptor*);
extern void destroy(Static12cf0*);
struct Static12cf0 {
    void* value;
    Static12cf0() { construct(this, &descriptor); }
    ~Static12cf0() { destroy(this); }
};
