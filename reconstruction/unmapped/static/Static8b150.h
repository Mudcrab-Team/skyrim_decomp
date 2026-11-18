// Source exposure: binary-analysis
// Static8b150, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b150;
extern void construct(Static8b150*, const Descriptor*);
extern void destroy(Static8b150*);
struct Static8b150 {
    void* value;
    Static8b150() { construct(this, &descriptor); }
    ~Static8b150() { destroy(this); }
};
