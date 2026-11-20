// Source exposure: binary-analysis; no external implementation source reused.
// Static176a020, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176a020;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176a020*);
    virtual void release(Static176a020*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176a020*);
struct Static176a020 {
    void* value;
    Static176a020();
    ~Static176a020() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
