// Source exposure: binary-analysis; no external implementation source reused.
// Static1797380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1797380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1797380*);
    virtual void release(Static1797380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1797380*);
struct Static1797380 {
    void* value;
    Static1797380();
    ~Static1797380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
