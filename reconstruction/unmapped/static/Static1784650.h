// Source exposure: binary-analysis; no external implementation source reused.
// Static1784650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784650*);
    virtual void release(Static1784650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784650*);
struct Static1784650 {
    void* value;
    Static1784650();
    ~Static1784650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
