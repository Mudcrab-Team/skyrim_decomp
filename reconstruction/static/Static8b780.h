// Source exposure: binary-analysis
// Static8b780, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b780;
extern void construct(Static8b780*, const Descriptor*);
extern void destroy(Static8b780*);
struct Static8b780 {
    void* value;
    Static8b780() { construct(this, &descriptor); }
    ~Static8b780() { destroy(this); }
};
