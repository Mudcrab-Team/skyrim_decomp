// Source exposure: binary-analysis
// Static14f80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static14f80;
extern void construct(Static14f80*, const Descriptor*);
extern void destroy(Static14f80*);
struct Static14f80 {
    void* value;
    Static14f80() { construct(this, &descriptor); }
    ~Static14f80() { destroy(this); }
};
