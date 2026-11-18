// Source exposure: binary-analysis; no external implementation source reused.
// Static176a520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a520*);
    virtual void release(Static176a520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a520*);
struct Static176a520 {
    void* value;
    Static176a520();
    ~Static176a520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
