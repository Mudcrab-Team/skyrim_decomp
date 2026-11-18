// Source exposure: binary-analysis; no external implementation source reused.
// Static1769990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769990*);
    virtual void release(Static1769990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769990*);
struct Static1769990 {
    void* value;
    Static1769990();
    ~Static1769990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
