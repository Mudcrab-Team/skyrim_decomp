// Source exposure: binary-analysis; no external implementation source reused.
// Static1778d50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778d50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778d50*);
    virtual void release(Static1778d50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778d50*);
struct Static1778d50 {
    void* value;
    Static1778d50();
    ~Static1778d50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
