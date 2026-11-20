// Source exposure: binary-analysis; no external implementation source reused.
// Static1753410, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753410;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753410*);
    virtual void release(Static1753410*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753410*);
struct Static1753410 {
    void* value;
    Static1753410();
    ~Static1753410() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
