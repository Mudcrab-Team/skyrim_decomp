// Source exposure: binary-analysis; no external implementation source reused.
// Static1746850, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1746850;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1746850*);
    virtual void release(Static1746850*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1746850*);
struct Static1746850 {
    void* value;
    Static1746850();
    ~Static1746850() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
