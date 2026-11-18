// Source exposure: binary-analysis
// Static8aee0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8aee0;
extern void construct(Static8aee0*, const Descriptor*);
extern void destroy(Static8aee0*);
struct Static8aee0 {
    void* value;
    Static8aee0() { construct(this, &descriptor); }
    ~Static8aee0() { destroy(this); }
};
