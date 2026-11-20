// Source exposure: binary-analysis
// Static8b510, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b510;
extern void construct(Static8b510*, const Descriptor*);
extern void destroy(Static8b510*);
struct Static8b510 {
    void* value;
    Static8b510() { construct(this, &descriptor); }
    ~Static8b510() { destroy(this); }
};
