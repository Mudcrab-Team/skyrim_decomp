// Source exposure: binary-analysis; no external implementation source reused.
// Static1743330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743330*);
    virtual void release(Static1743330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743330*);
struct Static1743330 {
    void* value;
    Static1743330();
    ~Static1743330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
