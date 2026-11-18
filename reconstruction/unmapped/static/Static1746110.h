// Source exposure: binary-analysis; no external implementation source reused.
// Static1746110, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1746110;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1746110*);
    virtual void release(Static1746110*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1746110*);
struct Static1746110 {
    void* value;
    Static1746110();
    ~Static1746110() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
