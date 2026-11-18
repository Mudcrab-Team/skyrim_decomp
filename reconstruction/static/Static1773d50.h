// Source exposure: binary-analysis; no external implementation source reused.
// Static1773d50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773d50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773d50*);
    virtual void release(Static1773d50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773d50*);
struct Static1773d50 {
    void* value;
    Static1773d50();
    ~Static1773d50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
