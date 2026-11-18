// Source exposure: binary-analysis; no external implementation source reused.
// Static1744650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1744650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1744650*);
    virtual void release(Static1744650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1744650*);
struct Static1744650 {
    void* value;
    Static1744650();
    ~Static1744650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
