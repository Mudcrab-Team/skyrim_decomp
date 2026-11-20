// Source exposure: binary-analysis
// Static8b690, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8b690;
extern void construct(Static8b690*, const Descriptor*);
extern void destroy(Static8b690*);
struct Static8b690 {
    void* value;
    Static8b690() { construct(this, &descriptor); }
    ~Static8b690() { destroy(this); }
};
