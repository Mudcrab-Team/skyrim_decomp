// Source exposure: binary-analysis
// Static17dd0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static17dd0;
extern void construct(Static17dd0*, const Descriptor*);
extern void destroy(Static17dd0*);
struct Static17dd0 {
    void* value;
    Static17dd0() { construct(this, &descriptor); }
    ~Static17dd0() { destroy(this); }
};
