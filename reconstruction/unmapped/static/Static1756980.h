// Source exposure: binary-analysis; no external implementation source reused.
// Static1756980, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756980;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756980*);
    virtual void release(Static1756980*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756980*);
struct Static1756980 {
    void* value;
    Static1756980();
    ~Static1756980() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
