// Source exposure: binary-analysis; no external implementation source reused.
// Static1799580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1799580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1799580*);
    virtual void release(Static1799580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1799580*);
struct Static1799580 {
    void* value;
    Static1799580();
    ~Static1799580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
