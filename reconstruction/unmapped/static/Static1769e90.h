// Source exposure: binary-analysis; no external implementation source reused.
// Static1769e90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769e90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769e90*);
    virtual void release(Static1769e90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769e90*);
struct Static1769e90 {
    void* value;
    Static1769e90();
    ~Static1769e90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
