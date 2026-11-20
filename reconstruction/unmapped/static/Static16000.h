// Source exposure: binary-analysis
// Static16000, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static16000;
extern void construct(Static16000*, const Descriptor*);
extern void destroy(Static16000*);
struct Static16000 {
    void* value;
    Static16000() { construct(this, &descriptor); }
    ~Static16000() { destroy(this); }
};
