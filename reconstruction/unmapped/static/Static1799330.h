// Source exposure: binary-analysis; no external implementation source reused.
// Static1799330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1799330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1799330*);
    virtual void release(Static1799330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1799330*);
struct Static1799330 {
    void* value;
    Static1799330();
    ~Static1799330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
