// Source exposure: binary-analysis; no external implementation source reused.
// Static1771230, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771230;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771230*);
    virtual void release(Static1771230*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771230*);
struct Static1771230 {
    void* value;
    Static1771230();
    ~Static1771230() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
