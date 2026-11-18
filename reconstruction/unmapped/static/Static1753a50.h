// Source exposure: binary-analysis; no external implementation source reused.
// Static1753a50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753a50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753a50*);
    virtual void release(Static1753a50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753a50*);
struct Static1753a50 {
    void* value;
    Static1753a50();
    ~Static1753a50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
