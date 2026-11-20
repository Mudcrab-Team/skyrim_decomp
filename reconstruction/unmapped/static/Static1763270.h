// Source exposure: binary-analysis; no external implementation source reused.
// Static1763270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763270*);
    virtual void release(Static1763270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763270*);
struct Static1763270 {
    void* value;
    Static1763270();
    ~Static1763270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
