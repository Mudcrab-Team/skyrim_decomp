// Source exposure: binary-analysis; no external implementation source reused.
// Static1760200, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760200;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760200*);
    virtual void release(Static1760200*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760200*);
struct Static1760200 {
    void* value;
    Static1760200();
    ~Static1760200() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
