// Source exposure: binary-analysis; no external implementation source reused.
// Static177a740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a740*);
    virtual void release(Static177a740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a740*);
struct Static177a740 {
    void* value;
    Static177a740();
    ~Static177a740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
