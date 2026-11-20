// Source exposure: binary-analysis
// Static8f610, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8f610;
extern void construct(Static8f610*, const Descriptor*);
extern void destroy(Static8f610*);
struct Static8f610 {
    void* value;
    Static8f610() { construct(this, &descriptor); }
    ~Static8f610() { destroy(this); }
};
