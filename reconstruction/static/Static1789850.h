// Source exposure: binary-analysis; no external implementation source reused.
// Static1789850, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1789850;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1789850*);
    virtual void release(Static1789850*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1789850*);
struct Static1789850 {
    void* value;
    Static1789850();
    ~Static1789850() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
