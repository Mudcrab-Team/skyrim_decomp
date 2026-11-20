// Source exposure: binary-analysis; no external implementation source reused.
// Static1772e00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772e00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772e00*);
    virtual void release(Static1772e00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772e00*);
struct Static1772e00 {
    void* value;
    Static1772e00();
    ~Static1772e00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
