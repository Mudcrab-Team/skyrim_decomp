// Source exposure: binary-analysis; no external implementation source reused.
// Static1779980, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779980;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779980*);
    virtual void release(Static1779980*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779980*);
struct Static1779980 {
    void* value;
    Static1779980();
    ~Static1779980() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
