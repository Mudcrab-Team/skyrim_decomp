// Source exposure: binary-analysis; no external implementation source reused.
// Static1784380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784380*);
    virtual void release(Static1784380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784380*);
struct Static1784380 {
    void* value;
    Static1784380();
    ~Static1784380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
