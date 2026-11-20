// Source exposure: binary-analysis; no external implementation source reused.
// Static1772590, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772590;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772590*);
    virtual void release(Static1772590*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772590*);
struct Static1772590 {
    void* value;
    Static1772590();
    ~Static1772590() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
