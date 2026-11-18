// Source exposure: binary-analysis
// Static102fe0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static102fe0;
extern void construct(Static102fe0*, const Descriptor*);
extern void destroy(Static102fe0*);
struct Static102fe0 {
    void* value;
    Static102fe0() { construct(this, &descriptor); }
    ~Static102fe0() { destroy(this); }
};
