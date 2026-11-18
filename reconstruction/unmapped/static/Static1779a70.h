// Source exposure: binary-analysis; no external implementation source reused.
// Static1779a70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779a70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779a70*);
    virtual void release(Static1779a70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779a70*);
struct Static1779a70 {
    void* value;
    Static1779a70();
    ~Static1779a70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
