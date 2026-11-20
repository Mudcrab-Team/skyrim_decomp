// Source exposure: binary-analysis; no external implementation source reused.
// Static174b910, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174b910;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174b910*);
    virtual void release(Static174b910*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174b910*);
struct Static174b910 {
    void* value;
    Static174b910();
    ~Static174b910() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
