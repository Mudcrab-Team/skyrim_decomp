// Source exposure: binary-analysis
// Static14e60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static14e60;
extern void construct(Static14e60*, const Descriptor*);
extern void destroy(Static14e60*);
struct Static14e60 {
    void* value;
    Static14e60() { construct(this, &descriptor); }
    ~Static14e60() { destroy(this); }
};
