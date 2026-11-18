// Source exposure: binary-analysis; no external implementation source reused.
// Static173f660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f660*);
    virtual void release(Static173f660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f660*);
struct Static173f660 {
    void* value;
    Static173f660();
    ~Static173f660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
