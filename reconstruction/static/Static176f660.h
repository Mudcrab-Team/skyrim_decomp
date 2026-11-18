// Source exposure: binary-analysis; no external implementation source reused.
// Static176f660, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f660;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f660*);
    virtual void release(Static176f660*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f660*);
struct Static176f660 {
    void* value;
    Static176f660();
    ~Static176f660() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
