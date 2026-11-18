// Source exposure: binary-analysis; no external implementation source reused.
// Static1748280, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1748280;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1748280*);
    virtual void release(Static1748280*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1748280*);
struct Static1748280 {
    void* value;
    Static1748280();
    ~Static1748280() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
