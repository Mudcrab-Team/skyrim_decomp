// Source exposure: binary-analysis; no external implementation source reused.
// Static1743ca0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743ca0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743ca0*);
    virtual void release(Static1743ca0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743ca0*);
struct Static1743ca0 {
    void* value;
    Static1743ca0();
    ~Static1743ca0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
