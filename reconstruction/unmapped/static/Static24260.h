// Source exposure: binary-analysis
// Static24260, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static24260;
extern void construct(Static24260*, const Descriptor*);
extern void destroy(Static24260*);
struct Static24260 {
    void* value;
    Static24260() { construct(this, &descriptor); }
    ~Static24260() { destroy(this); }
};
