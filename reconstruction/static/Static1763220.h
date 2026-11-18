// Source exposure: binary-analysis; no external implementation source reused.
// Static1763220, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763220;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763220*);
    virtual void release(Static1763220*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763220*);
struct Static1763220 {
    void* value;
    Static1763220();
    ~Static1763220() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
