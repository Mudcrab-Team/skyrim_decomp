// Source exposure: binary-analysis; no external implementation source reused.
// Static1748410, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1748410;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1748410*);
    virtual void release(Static1748410*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1748410*);
struct Static1748410 {
    void* value;
    Static1748410();
    ~Static1748410() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
