// Source exposure: binary-analysis
// Static8b450, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b450;
extern void construct(Static8b450*, const Descriptor*);
extern void destroy(Static8b450*);
struct Static8b450 {
    void* value;
    Static8b450() { construct(this, &descriptor); }
    ~Static8b450() { destroy(this); }
};
