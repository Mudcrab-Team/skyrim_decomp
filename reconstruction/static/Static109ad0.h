// Source exposure: binary-analysis
// Static109ad0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109ad0;
extern void construct(Static109ad0*, const Descriptor*);
extern void destroy(Static109ad0*);
struct Static109ad0 {
    void* value;
    Static109ad0() { construct(this, &descriptor); }
    ~Static109ad0() { destroy(this); }
};
