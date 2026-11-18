// Source exposure: binary-analysis; no external implementation source reused.
// Static1766330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766330*);
    virtual void release(Static1766330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766330*);
struct Static1766330 {
    void* value;
    Static1766330();
    ~Static1766330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
