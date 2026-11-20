// Source exposure: binary-analysis; no external implementation source reused.
// Static1773f30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773f30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773f30*);
    virtual void release(Static1773f30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773f30*);
struct Static1773f30 {
    void* value;
    Static1773f30();
    ~Static1773f30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
