// Source exposure: binary-analysis; no external implementation source reused.
// Static1777590, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777590;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777590*);
    virtual void release(Static1777590*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777590*);
struct Static1777590 {
    void* value;
    Static1777590();
    ~Static1777590() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
