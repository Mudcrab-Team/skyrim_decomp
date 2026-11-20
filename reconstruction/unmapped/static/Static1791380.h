// Source exposure: binary-analysis; no external implementation source reused.
// Static1791380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1791380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1791380*);
    virtual void release(Static1791380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1791380*);
struct Static1791380 {
    void* value;
    Static1791380();
    ~Static1791380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
