// Source exposure: binary-analysis; no external implementation source reused.
// Static177fc90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177fc90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177fc90*);
    virtual void release(Static177fc90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177fc90*);
struct Static177fc90 {
    void* value;
    Static177fc90();
    ~Static177fc90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
