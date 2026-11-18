// Source exposure: binary-analysis; no external implementation source reused.
// Static1779160, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779160;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779160*);
    virtual void release(Static1779160*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779160*);
struct Static1779160 {
    void* value;
    Static1779160();
    ~Static1779160() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
