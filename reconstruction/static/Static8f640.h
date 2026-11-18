// Source exposure: binary-analysis
// Static8f640, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8f640;
extern void construct(Static8f640*, const Descriptor*);
extern void destroy(Static8f640*);
struct Static8f640 {
    void* value;
    Static8f640() { construct(this, &descriptor); }
    ~Static8f640() { destroy(this); }
};
