// Source exposure: binary-analysis; no external implementation source reused.
// Static1740220, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740220;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740220*);
    virtual void release(Static1740220*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740220*);
struct Static1740220 {
    void* value;
    Static1740220();
    ~Static1740220() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
