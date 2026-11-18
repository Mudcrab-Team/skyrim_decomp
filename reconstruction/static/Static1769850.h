// Source exposure: binary-analysis; no external implementation source reused.
// Static1769850, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769850;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769850*);
    virtual void release(Static1769850*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769850*);
struct Static1769850 {
    void* value;
    Static1769850();
    ~Static1769850() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
