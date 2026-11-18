// Source exposure: binary-analysis; no external implementation source reused.
// Static1791490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1791490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1791490*);
    virtual void release(Static1791490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1791490*);
struct Static1791490 {
    void* value;
    Static1791490();
    ~Static1791490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
