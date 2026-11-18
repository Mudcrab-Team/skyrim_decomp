// Source exposure: binary-analysis; no external implementation source reused.
// Static1782d50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782d50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782d50*);
    virtual void release(Static1782d50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782d50*);
struct Static1782d50 {
    void* value;
    Static1782d50();
    ~Static1782d50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
