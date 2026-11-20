// Source exposure: binary-analysis; no external implementation source reused.
// Static1774520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774520*);
    virtual void release(Static1774520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774520*);
struct Static1774520 {
    void* value;
    Static1774520();
    ~Static1774520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
