// Source exposure: binary-analysis; no external implementation source reused.
// Static1742520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742520*);
    virtual void release(Static1742520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742520*);
struct Static1742520 {
    void* value;
    Static1742520();
    ~Static1742520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
