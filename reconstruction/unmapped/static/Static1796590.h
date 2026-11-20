// Source exposure: binary-analysis; no external implementation source reused.
// Static1796590, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796590;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796590*);
    virtual void release(Static1796590*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796590*);
struct Static1796590 {
    void* value;
    Static1796590();
    ~Static1796590() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
