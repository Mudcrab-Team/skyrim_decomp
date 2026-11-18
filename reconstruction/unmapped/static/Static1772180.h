// Source exposure: binary-analysis; no external implementation source reused.
// Static1772180, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772180;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772180*);
    virtual void release(Static1772180*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772180*);
struct Static1772180 {
    void* value;
    Static1772180();
    ~Static1772180() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
