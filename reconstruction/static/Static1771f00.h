// Source exposure: binary-analysis; no external implementation source reused.
// Static1771f00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771f00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771f00*);
    virtual void release(Static1771f00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771f00*);
struct Static1771f00 {
    void* value;
    Static1771f00();
    ~Static1771f00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
