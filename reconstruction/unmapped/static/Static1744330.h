// Source exposure: binary-analysis; no external implementation source reused.
// Static1744330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744330*);
    virtual void release(Static1744330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744330*);
struct Static1744330 {
    void* value;
    Static1744330();
    ~Static1744330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
