// Source exposure: binary-analysis; no external implementation source reused.
// Static176d220, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d220;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d220*);
    virtual void release(Static176d220*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d220*);
struct Static176d220 {
    void* value;
    Static176d220();
    ~Static176d220() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
