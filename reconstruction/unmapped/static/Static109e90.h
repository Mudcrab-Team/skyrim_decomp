// Source exposure: binary-analysis
// Static109e90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static109e90;
extern void construct(Static109e90*, const Descriptor*);
extern void destroy(Static109e90*);
struct Static109e90 {
    void* value;
    Static109e90() { construct(this, &descriptor); }
    ~Static109e90() { destroy(this); }
};
