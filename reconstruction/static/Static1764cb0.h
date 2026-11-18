// Source exposure: binary-analysis; no external implementation source reused.
// Static1764cb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764cb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764cb0*);
    virtual void release(Static1764cb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764cb0*);
struct Static1764cb0 {
    void* value;
    Static1764cb0();
    ~Static1764cb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
