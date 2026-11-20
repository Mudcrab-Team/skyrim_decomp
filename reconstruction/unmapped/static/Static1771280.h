// Source exposure: binary-analysis; no external implementation source reused.
// Static1771280, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771280;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771280*);
    virtual void release(Static1771280*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771280*);
struct Static1771280 {
    void* value;
    Static1771280();
    ~Static1771280() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
