// Source exposure: binary-analysis; no external implementation source reused.
// Static1759270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759270*);
    virtual void release(Static1759270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759270*);
struct Static1759270 {
    void* value;
    Static1759270();
    ~Static1759270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
