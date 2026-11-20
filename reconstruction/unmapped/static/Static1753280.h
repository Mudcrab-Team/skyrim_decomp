// Source exposure: binary-analysis; no external implementation source reused.
// Static1753280, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753280;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753280*);
    virtual void release(Static1753280*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753280*);
struct Static1753280 {
    void* value;
    Static1753280();
    ~Static1753280() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
