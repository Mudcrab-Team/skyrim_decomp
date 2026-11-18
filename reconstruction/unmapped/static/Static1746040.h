// Source exposure: binary-analysis; no external implementation source reused.
// Static1746040, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1746040;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1746040*);
    virtual void release(Static1746040*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1746040*);
struct Static1746040 {
    void* value;
    Static1746040();
    ~Static1746040() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
