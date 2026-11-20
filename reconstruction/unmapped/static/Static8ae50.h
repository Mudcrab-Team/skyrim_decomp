// Source exposure: binary-analysis
// Static8ae50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8ae50;
extern void construct(Static8ae50*, const Descriptor*);
extern void destroy(Static8ae50*);
struct Static8ae50 {
    void* value;
    Static8ae50() { construct(this, &descriptor); }
    ~Static8ae50() { destroy(this); }
};
