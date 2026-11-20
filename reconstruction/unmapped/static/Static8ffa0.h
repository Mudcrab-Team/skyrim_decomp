// Source exposure: binary-analysis
// Static8ffa0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8ffa0;
extern void construct(Static8ffa0*, const Descriptor*);
extern void destroy(Static8ffa0*);
struct Static8ffa0 {
    void* value;
    Static8ffa0() { construct(this, &descriptor); }
    ~Static8ffa0() { destroy(this); }
};
