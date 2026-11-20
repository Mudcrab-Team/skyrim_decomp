// Source exposure: binary-analysis
// Static8b270, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b270;
extern void construct(Static8b270*, const Descriptor*);
extern void destroy(Static8b270*);
struct Static8b270 {
    void* value;
    Static8b270() { construct(this, &descriptor); }
    ~Static8b270() { destroy(this); }
};
