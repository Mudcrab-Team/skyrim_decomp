// Source exposure: binary-analysis; no external implementation source reused.
// Static1775330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775330*);
    virtual void release(Static1775330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775330*);
struct Static1775330 {
    void* value;
    Static1775330();
    ~Static1775330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
