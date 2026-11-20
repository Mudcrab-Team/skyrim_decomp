// Source exposure: binary-analysis; no external implementation source reused.
// Static1743c50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743c50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743c50*);
    virtual void release(Static1743c50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743c50*);
struct Static1743c50 {
    void* value;
    Static1743c50();
    ~Static1743c50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
