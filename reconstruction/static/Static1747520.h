// Source exposure: binary-analysis; no external implementation source reused.
// Static1747520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1747520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1747520*);
    virtual void release(Static1747520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1747520*);
struct Static1747520 {
    void* value;
    Static1747520();
    ~Static1747520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
