// Source exposure: binary-analysis; no external implementation source reused.
// Static1778850, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778850;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778850*);
    virtual void release(Static1778850*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778850*);
struct Static1778850 {
    void* value;
    Static1778850();
    ~Static1778850() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
