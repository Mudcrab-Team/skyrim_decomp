// Source exposure: binary-analysis; no external implementation source reused.
// Static1779520, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779520;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779520*);
    virtual void release(Static1779520*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779520*);
struct Static1779520 {
    void* value;
    Static1779520();
    ~Static1779520() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
