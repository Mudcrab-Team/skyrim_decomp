// Source exposure: binary-analysis
// Static21220, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21220;
extern void construct(Static21220*, const Descriptor*);
extern void destroy(Static21220*);
struct Static21220 {
    void* value;
    Static21220() { construct(this, &descriptor); }
    ~Static21220() { destroy(this); }
};
