// Source exposure: binary-analysis
// Static14e90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static14e90;
extern void construct(Static14e90*, const Descriptor*);
extern void destroy(Static14e90*);
struct Static14e90 {
    void* value;
    Static14e90() { construct(this, &descriptor); }
    ~Static14e90() { destroy(this); }
};
