// Source exposure: binary-analysis
// Static14bf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static14bf0;
extern void construct(Static14bf0*, const Descriptor*);
extern void destroy(Static14bf0*);
struct Static14bf0 {
    void* value;
    Static14bf0() { construct(this, &descriptor); }
    ~Static14bf0() { destroy(this); }
};
