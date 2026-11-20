// Source exposure: binary-analysis; no external implementation source reused.
// Static176b510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176b510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176b510*);
    virtual void release(Static176b510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176b510*);
struct Static176b510 {
    void* value;
    Static176b510();
    ~Static176b510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
