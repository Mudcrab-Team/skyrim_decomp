// Source exposure: binary-analysis; no external implementation source reused.
// Static1765110, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765110;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765110*);
    virtual void release(Static1765110*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765110*);
struct Static1765110 {
    void* value;
    Static1765110();
    ~Static1765110() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
