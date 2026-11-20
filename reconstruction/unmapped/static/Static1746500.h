// Source exposure: binary-analysis; no external implementation source reused.
// Static1746500, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1746500;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1746500*);
    virtual void release(Static1746500*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1746500*);
struct Static1746500 {
    void* value;
    Static1746500();
    ~Static1746500() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
