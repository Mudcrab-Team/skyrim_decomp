// Source exposure: binary-analysis; no external implementation source reused.
// Static1765520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765520*);
    virtual void release(Static1765520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765520*);
struct Static1765520 {
    void* value;
    Static1765520();
    ~Static1765520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
