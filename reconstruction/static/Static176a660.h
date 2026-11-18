// Source exposure: binary-analysis; no external implementation source reused.
// Static176a660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a660*);
    virtual void release(Static176a660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a660*);
struct Static176a660 {
    void* value;
    Static176a660();
    ~Static176a660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
