// Source exposure: binary-analysis; no external implementation source reused.
// Static1798510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1798510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1798510*);
    virtual void release(Static1798510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1798510*);
struct Static1798510 {
    void* value;
    Static1798510();
    ~Static1798510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
