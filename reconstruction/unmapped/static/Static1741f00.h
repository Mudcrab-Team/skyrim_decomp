// Source exposure: binary-analysis; no external implementation source reused.
// Static1741f00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1741f00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1741f00*);
    virtual void release(Static1741f00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1741f00*);
struct Static1741f00 {
    void* value;
    Static1741f00();
    ~Static1741f00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
