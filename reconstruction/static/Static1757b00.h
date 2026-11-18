// Source exposure: binary-analysis; no external implementation source reused.
// Static1757b00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757b00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757b00*);
    virtual void release(Static1757b00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757b00*);
struct Static1757b00 {
    void* value;
    Static1757b00();
    ~Static1757b00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
