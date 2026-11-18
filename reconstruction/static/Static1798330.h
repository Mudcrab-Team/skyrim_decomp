// Source exposure: binary-analysis; no external implementation source reused.
// Static1798330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1798330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1798330*);
    virtual void release(Static1798330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1798330*);
struct Static1798330 {
    void* value;
    Static1798330();
    ~Static1798330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
