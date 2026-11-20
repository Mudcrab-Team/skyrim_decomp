// Source exposure: binary-analysis; no external implementation source reused.
// Static1753460, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753460;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753460*);
    virtual void release(Static1753460*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753460*);
struct Static1753460 {
    void* value;
    Static1753460();
    ~Static1753460() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
