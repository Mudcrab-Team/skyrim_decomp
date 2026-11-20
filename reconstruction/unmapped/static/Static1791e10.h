// Source exposure: binary-analysis; no external implementation source reused.
// Static1791e10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1791e10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1791e10*);
    virtual void release(Static1791e10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1791e10*);
struct Static1791e10 {
    void* value;
    Static1791e10();
    ~Static1791e10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
