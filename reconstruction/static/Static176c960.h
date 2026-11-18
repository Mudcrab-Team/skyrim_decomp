// Source exposure: binary-analysis; no external implementation source reused.
// Static176c960, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c960;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c960*);
    virtual void release(Static176c960*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c960*);
struct Static176c960 {
    void* value;
    Static176c960();
    ~Static176c960() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
