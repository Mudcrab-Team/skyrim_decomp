// Source exposure: binary-analysis
// Static14e00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static14e00;
extern void construct(Static14e00*, const Descriptor*);
extern void destroy(Static14e00*);
struct Static14e00 {
    void* value;
    Static14e00() { construct(this, &descriptor); }
    ~Static14e00() { destroy(this); }
};
