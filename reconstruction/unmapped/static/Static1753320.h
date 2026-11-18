// Source exposure: binary-analysis; no external implementation source reused.
// Static1753320, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753320;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753320*);
    virtual void release(Static1753320*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753320*);
struct Static1753320 {
    void* value;
    Static1753320();
    ~Static1753320() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
