// Source exposure: binary-analysis; no external implementation source reused.
// Static176e580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176e580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176e580*);
    virtual void release(Static176e580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176e580*);
struct Static176e580 {
    void* value;
    Static176e580();
    ~Static176e580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
