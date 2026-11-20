// Source exposure: binary-analysis; no external implementation source reused.
// Static1746270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1746270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1746270*);
    virtual void release(Static1746270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1746270*);
struct Static1746270 {
    void* value;
    Static1746270();
    ~Static1746270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
