// Source exposure: binary-analysis; no external implementation source reused.
// Static176c370, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c370;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c370*);
    virtual void release(Static176c370*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c370*);
struct Static176c370 {
    void* value;
    Static176c370();
    ~Static176c370() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
