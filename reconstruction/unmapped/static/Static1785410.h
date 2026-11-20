// Source exposure: binary-analysis; no external implementation source reused.
// Static1785410, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785410;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785410*);
    virtual void release(Static1785410*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785410*);
struct Static1785410 {
    void* value;
    Static1785410();
    ~Static1785410() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
