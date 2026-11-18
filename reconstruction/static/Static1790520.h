// Source exposure: binary-analysis; no external implementation source reused.
// Static1790520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790520*);
    virtual void release(Static1790520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790520*);
struct Static1790520 {
    void* value;
    Static1790520();
    ~Static1790520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
