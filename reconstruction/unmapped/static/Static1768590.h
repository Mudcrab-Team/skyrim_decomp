// Source exposure: binary-analysis; no external implementation source reused.
// Static1768590, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768590;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768590*);
    virtual void release(Static1768590*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768590*);
struct Static1768590 {
    void* value;
    Static1768590();
    ~Static1768590() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
