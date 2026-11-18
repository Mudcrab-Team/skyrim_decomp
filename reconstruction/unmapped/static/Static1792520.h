// Source exposure: binary-analysis; no external implementation source reused.
// Static1792520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1792520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1792520*);
    virtual void release(Static1792520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1792520*);
struct Static1792520 {
    void* value;
    Static1792520();
    ~Static1792520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
