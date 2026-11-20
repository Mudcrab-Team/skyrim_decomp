// Source exposure: binary-analysis; no external implementation source reused.
// Static1754270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754270*);
    virtual void release(Static1754270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754270*);
struct Static1754270 {
    void* value;
    Static1754270();
    ~Static1754270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
