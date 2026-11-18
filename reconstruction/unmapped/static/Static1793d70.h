// Source exposure: binary-analysis; no external implementation source reused.
// Static1793d70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1793d70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1793d70*);
    virtual void release(Static1793d70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1793d70*);
struct Static1793d70 {
    void* value;
    Static1793d70();
    ~Static1793d70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
