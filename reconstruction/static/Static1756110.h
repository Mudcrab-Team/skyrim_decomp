// Source exposure: binary-analysis; no external implementation source reused.
// Static1756110, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756110;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756110*);
    virtual void release(Static1756110*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756110*);
struct Static1756110 {
    void* value;
    Static1756110();
    ~Static1756110() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
