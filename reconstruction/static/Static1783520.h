// Source exposure: binary-analysis; no external implementation source reused.
// Static1783520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783520*);
    virtual void release(Static1783520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783520*);
struct Static1783520 {
    void* value;
    Static1783520();
    ~Static1783520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
