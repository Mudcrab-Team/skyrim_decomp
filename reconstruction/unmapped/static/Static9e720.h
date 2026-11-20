// Source exposure: binary-analysis
// Static9e720, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9e720;
extern void construct(Static9e720*, const Descriptor*);
extern void destroy(Static9e720*);
struct Static9e720 {
    void* value;
    Static9e720() { construct(this, &descriptor); }
    ~Static9e720() { destroy(this); }
};
