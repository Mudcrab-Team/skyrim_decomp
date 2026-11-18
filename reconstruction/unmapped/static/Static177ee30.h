// Source exposure: binary-analysis; no external implementation source reused.
// Static177ee30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177ee30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177ee30*);
    virtual void release(Static177ee30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177ee30*);
struct Static177ee30 {
    void* value;
    Static177ee30();
    ~Static177ee30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
