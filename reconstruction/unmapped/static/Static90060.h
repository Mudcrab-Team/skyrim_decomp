// Source exposure: binary-analysis
// Static90060, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static90060;
extern void construct(Static90060*, const Descriptor*);
extern void destroy(Static90060*);
struct Static90060 {
    void* value;
    Static90060() { construct(this, &descriptor); }
    ~Static90060() { destroy(this); }
};
